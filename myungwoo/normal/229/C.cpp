#include <stdio.h>

#define MAXN 1000006
typedef unsigned long long lld;

int N,M,cnt[MAXN];
lld ans;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    int i,j,k;
    scanf("%d%d",&N,&M);
    ans = lld(N)*(N-1)/2*(N-2)/3;
    for (i=1;i<=M;i++){
        scanf("%d%d",&j,&k);
        cnt[j]++; cnt[k]++;
        ans += cnt[j]+cnt[k]-N;
    }
    printf("%I64d",ans);
}