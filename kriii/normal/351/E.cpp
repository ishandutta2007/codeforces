#include <stdio.h>

int N,X[2020],A[2020],B[2020],U;

int abs(int a){return a < 0 ? -a : a;}

int main()
{
    int i,j,k,c,d;

    scanf ("%d",&N);
    for (i=1;i<=N;i++) scanf ("%d",&X[i]), X[i] = abs(X[i]);
    for (k=0;k<1;k++){
        for (i=1;i<=N;i++){
            c = d = 0;
            for (j=1;j<i;j++){
                if (X[j] > X[i]) c++;
                if (X[j] > -X[i]) d++;
            }
            for (j=i+1;j<=N;j++){
                if (X[i] > X[j]) c++;
                if (-X[i] > X[j]) d++;
            }
            if (c >= d) X[i] = -X[i];
        }
    }

    for (i=1;i<=N;i++) for (j=1;j<i;j++) if (X[j] > X[i]) U++;
    printf ("%d",U);

    return 0;
}