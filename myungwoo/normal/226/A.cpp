#include <stdio.h>

typedef long long lld;

int N,M;
lld ans,k;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    scanf("%d%d",&N,&M);
    ans = 1;
    for (k=3;N;N>>=1,k=k*k%M) if (N&1) ans = ans*k%M;
    printf("%lld",(ans-1+M)%M);
}