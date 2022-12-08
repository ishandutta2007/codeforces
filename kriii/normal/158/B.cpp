#include <stdio.h>

int N,C[5],ANS;

int main()
{
    int t;

    scanf ("%d",&N);
    while (N--){
        scanf ("%d",&t);
        C[t]++;
    }

    ANS += C[4]; C[4] = 0;
    if (C[3] < C[1]) C[1] -= C[3];
    else C[1] = 0;
    ANS += C[3]; C[3] = 0;

    ANS += C[2] / 2; C[2] %= 2;
    if (C[2]) C[1] += 2, C[2] = 0;
    ANS += (C[1] + 3) / 4; C[1] = 0;

    printf ("%d",ANS);
    return 0;
}