#include <stdio.h>

int T,N,D[4],CN;
int CHK[10000];
char sd[4];
int main()
{
    int i;

    scanf ("%d",&T);
    for (i=0;i<T;i++){
        scanf ("%1d%1d\n%1d%1d",&D[0],&D[1],&D[3],&D[2]);
        N = D[0] * 1000 + D[1] * 100 + D[2] * 10 + D[3];
        if (CHK[N] == 0){
            CN++;
            CHK[D[0] * 1000 + D[1] * 100 + D[2] * 10 + D[3]] = 1;
            CHK[D[1] * 1000 + D[2] * 100 + D[3] * 10 + D[0]] = 1;
            CHK[D[2] * 1000 + D[3] * 100 + D[0] * 10 + D[1]] = 1;
            CHK[D[3] * 1000 + D[0] * 100 + D[1] * 10 + D[2]] = 1;
        }
        if (i < T-1) scanf ("%s",sd);
    }

    printf ("%d",CN);

    return 0;
}