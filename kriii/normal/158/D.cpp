#include <stdio.h>

int N,t[20202],s[20202],ANS=0x80000000;

int main()
{
    int i,j,d;

    scanf ("%d",&N);
    for (i=0;i<N;i++) scanf ("%d",&t[i]);
    for (i=3;i<=N;i++) if (N % i == 0) {
        d = N / i;
        for (j=0;j<d;j++) s[j] = 0;
        for (j=0;j<N;j++) s[j%d] += t[j];
        for (j=0;j<d;j++){
            if (ANS < s[j]) ANS = s[j];
        }
    }
    printf ("%d",ANS);

    return 0;
}