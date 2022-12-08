#include <stdio.h>
#include <algorithm>

int N,A[500001];

bool good(int x)
{
    int i;

    for (i=0;i<x;i++){
        if (A[i] * 2 > A[N-x+i]) return false;
    }

    return true;
}

int main()
{
    int i,j;

    scanf ("%d",&N);
    for (i=0;i<N;i++) scanf ("%d",&A[i]);
    std::sort(A,A+N);

    int l = 0, r = N / 2, m, a;
    while (l <= r){
        m = (l + r) / 2;
        if (good(m)){
            a = m;
            l = m + 1;
        }
        else r = m - 1;
    }

    printf ("%d",N-a);

    return 0;
}