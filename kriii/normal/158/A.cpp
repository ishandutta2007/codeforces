#include <stdio.h>

int N,K,S[55],R[55],C;

int main()
{
    int i;

    scanf ("%d %d",&N,&K);

    S[0] = 101;
    for (i=1;i<=N;i++){
        scanf ("%d",&S[i]); R[i] = R[i-1];
        if (S[i] != S[i-1]) R[i] = i;
        if (R[i] <= K && S[i] > 0) C++;
    }
    printf ("%d",C);

    return 0;
}