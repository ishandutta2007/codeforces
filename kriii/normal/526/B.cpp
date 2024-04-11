#include <stdio.h>
#include <algorithm>
using namespace std;

int N,A[2048];

int main()
{
    scanf ("%d",&N);
    for (int i=2;i<(1<<(N+1));i++){
        scanf ("%d",&A[i]);
        A[i] += A[i/2];
    }

    long long mx = 0, c = 0;
    for (int i=(1<<N);i<(1<<(N+1));i++){
        if (mx < A[i])
            mx = A[i];
    }
    for (int i=(1<<(N+1))-1;i>=1;i--){
        if (i < (1<<N)){
            A[i] = min(A[i*2],A[i*2+1]);
            c += A[i*2]+A[i*2+1]-A[i]*2;
        }
        else A[i] = mx - A[i];
    }
    printf ("%lld\n",c);

    return 0;
}