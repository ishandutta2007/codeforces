#include <stdio.h>

int A[3030],INV; long long ans;

int main()
{
    int N,i,j;

    scanf ("%d",&N);
    for (i=0;i<N;i++){
        scanf ("%d",&A[i]);
        for (j=0;j<i;j++) if (A[j] > A[i]) INV++;
    }

    ans = (INV / 2) * 4;
    if (INV % 2) ans++;
    printf ("%lld.000000",ans);

    return 0;
}