#include <stdio.h>

const int lim = 10000000;
int V[lim + 1],A,N;
long long ans;

int main()
{
    int i,j;

    for (i=1;i<=lim;i++) V[i] = i;
    for (i=2;i*i<=lim;i++){
        V[i*i] = 1;
        for (j=2;i*i*j<=lim;j++){
            if (V[i*i*j] > j) V[i*i*j] = j;
        }
    }

    scanf ("%d %d",&A,&N);
    for (i=A;i<A+N;i++) ans += V[i];
    printf ("%I64d",ans);

    return 0;
}