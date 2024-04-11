/*
    author:     MarX and ArielxX
    school:     UH
*/

#include <stdio.h>

using namespace std;



int main()
{
    int canciones, tiempo;
    scanf("%d%d",&canciones,&tiempo);
    int value = 0;
    int chistes = 0;
    int suma = 0;
    for (int i = 0; i < canciones; ++i)
    {
        scanf("%d",&value);
        tiempo -= value;
        tiempo -= 10;
        chistes += 2;
    }
    tiempo += 10;
    chistes -= 2;
    if (tiempo >= 0)
    {
        chistes += tiempo/5;
        printf("%d\n",chistes);
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}