#include <stdio.h>
#include <stdlib.h>
int getHashCode(char *string) {
    /*
    int code=0;
    while(*string++)
        code+=*string;
    return code%256;
*/
    int code=0;
    int postion=1;
    while(*string)
    {
        code +=(*string)*postion;
        postion++;
        string++;
    }
    return code%256;
}

struct node
{
    char *key;
    int frecuencia;
    struct node *next;
};

typedef struct node Node;

int keyExists(Node *hashTable[], char *key)
{
    if(hashTable[getHashCode(key)]==NULL)
        return 0;
    return 1;

}



int main() {
    /*
    char p[]="bca";
    getHashCode(p);
    printf("palabra: %s   codigo-> %d\n",p, getHashCode(p));
    char *arry[300]={NULL};
    arry[getHashCode(p)]=p;
    printf("%s\n",arry[getHashCode(p)]);
    printf("%s\n",arry[12]);
     */



    char *palabra1="hola";
    char *palabra2="hola";
    char *palabra3="adios";
    char *palabra4="hola";

    char *libro[]={palabra1,palabra2,palabra3,palabra4};



    //arreglo de nodos
    Node *hashTable[256]={NULL};

    for(int i=0;i<4;i++)
    {
        //obtener el codigo hash en base a la poscion del areeglo de libro
        int hashcode= getHashCode(libro[i]);
        if(hashTable[hashcode]==NULL)
        {
            //aqui ocurre la primera ocurrencia de esa palabra
            hashTable[hashcode]= malloc(sizeof(Node));
            hashTable[hashcode]->frecuencia=1;
            hashTable[hashcode]->key=libro[i];
            hashTable[hashcode]->next=NULL;
        }
        else  //si ya encuentra una repetida
        {
            hashTable[hashcode]->frecuencia++;
        }
    }

    if(keyExists(hashTable,"hola"))
        printf("La frecuencia de la palabra hola es : %d\n",hashTable[getHashCode("hola")]->frecuencia);
    return 0;
}
