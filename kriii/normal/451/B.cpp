#include <stdio.h>
#include <algorithm>

int N,A[100001],L[100001],R[100001];

int main()
{
    int l, r; 

    scanf ("%d",&N);
    for (int i=1;i<=N;i++) scanf ("%d",&A[i]);
    L[1] = 1; l = 1;
    for (int i=2;i<=N;i++){
        if (A[i-1] < A[i]) L[i] = 1, l = i;
        else break;
    }
    R[N] = 1; r = N;
    for (int i=N-1;i>=1;i--){
        if (A[i] < A[i+1]) R[i] = 1, r = i;
        else break;
    }

    if (R[1]){
        puts("yes");
        puts("1 1");
        return 0;
    }

    std::reverse(A+l,A+r+1);
    for (int i=2;i<=N;i++){
        if (A[i-1] > A[i]){
            puts("no");
            return 0;
        }
    }
    puts("yes");
    printf ("%d %d\n",l,r);

    return 0;
}