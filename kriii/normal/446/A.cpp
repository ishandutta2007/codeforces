#include <stdio.h>

int N,A[100001],L[100001],R[100001];

int main()
{
    int i;

    scanf ("%d",&N);
    for (int i=1;i<=N;i++) scanf ("%d",&A[i]);
    A[0] = -100; A[N+1] = 0x7fffffff;
    for (int i=1;i<=N;i++){
        if (A[i-1] < A[i]) L[i] = L[i-1] + 1;
        else L[i] = 1;
    }
    for (int i=N;i>=1;i--){
        if (A[i+1] > A[i]) R[i] = R[i+1] + 1;
        else R[i] = 1;
    }

    int a = 0;
    for (int i=1;i<=N;i++){
        if (a < L[i]) a = L[i];
        if (a < R[i]) a = R[i];
        if (a < L[i-1]+1) a = L[i-1]+1;
        if (a < R[i+1]+1) a = R[i+1]+1;
        if (A[i-1] + 1 < A[i+1]){
            if (a < L[i-1] + 1 + R[i+1])
                a = L[i-1] + 1 + R[i+1];
        }
    }

    printf ("%d\n",a);

    return 0;
}