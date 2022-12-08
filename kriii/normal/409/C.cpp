#include <stdio.h>


int main()
{
    int a,b,c,d,e;

    scanf ("%d %d %d %d %d",&a,&b,&c,&d,&e);
    int u = 10000;
    if (u > a) u = a;
    if (u > b) u = b;
    if (u > c / 2) u = c / 2;
    if (u > d / 7) u = d / 7;
    if (u > e / 4) u = e / 4;
    printf ("%d\n",u);

    return 0;
}