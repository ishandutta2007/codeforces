#include <stdio.h>

int N,A;

int main()
{
    int i;

    scanf ("%d",&N);
    for (i=0;i<N;i++){
        scanf ("%d",&A);
        while (A){
            putchar('P');
            A--;
            if (A == 0) break;
            else if (i+1 < N) printf ("RL");
            else printf ("LR");
        }
        if (i+1<N) putchar('R');
    }

    return 0;
}