#include <stdio.h>

int N, K, C, M, H[400], W;

int main()
{
    int i,t;

    scanf ("%d %d",&N,&K); C = K;
    scanf ("%d",&W);
    for (i=0;i<W;i++){
        scanf ("%d",&t); H[t] = 1;
    }

    for (i=1;i<=N;i++){
        if (H[i] || C <= i){
            M++; C = i + K;
        }
    }

    printf ("%d",M);

    return 0;
}