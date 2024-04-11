#include <stdio.h>

int N,M,V[1090];

int main()
{
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);

    int i;

    scanf ("%d %d",&N,&M);
    for (i=0;i<N;i++) scanf ("%d",&V[i]); M--;
    while (V[M]==0){
        M = (M + 1) % N;
    }

    printf ("%d",M+1);

    return 0;
}