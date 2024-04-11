#include <stdio.h>
#include <algorithm>
using namespace std;

typedef __int64 lld;

#define MAXP 300001

int K,seq[101];
lld N,D[101][MAXP];

lld dfs(int n,lld v)
{
    if (!n) return v;
    if (v < MAXP && D[n][v] != -1) return D[n][v];
    lld ret=dfs(n-1,v)-dfs(n-1,v/seq[n]);
    if (v < MAXP) D[n][v] = ret;
    return ret;
}

int main()
{
    int i,j,k;
    scanf("%I64d%d",&N,&K);
    for (i=1;i<=K;i++) scanf("%d",seq+i);
    sort(seq+1,seq+K+1);
    for (i=1;i<=K;i++) for (j=0;j<MAXP;j++) D[i][j] = -1;
    printf("%I64d",dfs(K,N));
}