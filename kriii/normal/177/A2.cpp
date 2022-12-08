#include <stdio.h>

int N,S;

int main()
{
    int i,j,x;

    scanf ("%d",&N);
    for (i=0;i<N;i++) for (j=0;j<N;j++){
        scanf ("%d",&x);
        if (i == j || i + j == N-1 || i == N/2 || j == N/2) S += x;
    }

    printf ("%d",S);

    return 0;
}