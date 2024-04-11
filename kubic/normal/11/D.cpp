#include <bits/stdc++.h>
using namespace std;
#define N 25
#define ll long long
#define S 1<<19
int n,m;ll ans,dp[S][N];bool e[N][N];
int main()
{
	scanf("%d %d",&n,&m);for(int i=1,u,v;i<=m;++i) scanf("%d %d",&u,&v),e[--u][--v]=e[v][u]=1;
	for(int i=0;i<n;++i) dp[1<<i][i]=1;
	for(int i=0;i<1<<n;++i) for(int j=0;j<n;++j) if(dp[i][j]) for(int k=0;k<n;++k) if(e[j][k] && (i&-i)<=1<<k)
		if(i&1<<k) {if((i&-i)==1<<k) ans+=dp[i][j];}else dp[i|1<<k][k]+=dp[i][j];
	printf("%lld\n",ans-m>>1);
}