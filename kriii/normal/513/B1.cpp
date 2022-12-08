#include <stdio.h>

int N,A[55]; long long M;

int main()
{
    scanf ("%d %lld",&N,&M); M--;

    int s = 0, e = N-1;
    for (int i=N-2;i>=0;i--){
        if (M < (1ll << i)){
            A[s] = N - i - 1; s++;
        }
        else{
            M -= (1ll << i);
            A[e] = N - i - 1; e--;
        }
    }
    A[s] = N;

    for (int i=0;i<N;i++) printf ("%d ",A[i]);

    return 0;
}