#include <stdio.h>

int a,b,m,r,C[100001];

int main()
{
    int i;

    scanf ("%d %d %d %d",&a,&b,&m,&r);

    for (i=1;;i++){
        if (C[r]){
            printf ("%d",i-C[r]);
            break;
        }
        C[r] = i;
        r = (a * r + b) % m;
    }

    return 0;
}