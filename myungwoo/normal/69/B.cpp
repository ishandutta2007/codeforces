#include <stdio.h>

int N,M,mnt[101],mnc[101],sum;

int main()
{
    int i,j,s,e,t,c;
    scanf("%d%d",&N,&M);
    for (i=1;i<=N;i++) mnt[i] = 1e9;
    for (i=1;i<=M;i++){
        scanf("%d%d%d%d",&s,&e,&t,&c);
        for (j=s;j<=e;j++) if (mnt[j] > t) mnt[j] = t, mnc[j] = c;
    }
    for (i=1;i<=N;i++) if (mnt[i] < 1e9) sum += mnc[i];
    printf("%d",sum);
}