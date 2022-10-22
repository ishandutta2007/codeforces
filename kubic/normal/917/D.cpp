#include <bits/stdc++.h>
using namespace std;
#define N 105
#define MOD 1000000007
#define pb push_back
int n,sz[N],ans[N],tmp[N][2],C[N][N],dp[N][N][2];vector<int> e[N];
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
int qPow(int x,int y)
{int res=1;for(;y;y/=2,x=1ll*x*x%MOD) if(y&1) res=1ll*res*x%MOD;return res;}
void dfs(int u,int f)
{
	sz[u]=dp[u][0][0]=dp[u][0][1]=1;
	for(auto v:e[u]) if(v!=f)
	{
		dfs(v,u);for(int i=0;i<sz[u]+sz[v];++i) tmp[i][0]=tmp[i][1]=0;
		for(int i=0;i<sz[u];++i) for(int j=0;j<sz[v];++j)
		{
			tmp[i+j][0]=add(tmp[i+j][0],1ll*dp[u][i][0]*dp[v][j][1]%MOD);
			tmp[i+j][1]=add(tmp[i+j][1],1ll*dp[u][i][1]*dp[v][j][1]%MOD);
			tmp[i+j+1][0]=add(tmp[i+j+1][0],1ll*dp[u][i][0]*dp[v][j][0]%MOD);
			tmp[i+j+1][1]=add(tmp[i+j+1][1],1ll*dp[u][i][0]*dp[v][j][1]%MOD);
			tmp[i+j+1][1]=add(tmp[i+j+1][1],1ll*dp[u][i][1]*dp[v][j][0]%MOD);
		}
		for(int i=0;i<sz[u]+sz[v];++i)
			dp[u][i][0]=tmp[i][0],dp[u][i][1]=tmp[i][1];sz[u]+=sz[v];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i) for(int j=0;j<=i;++j)
		C[i][j]=j?add(C[i-1][j],C[i-1][j-1]):1;
	for(int i=1,u,v;i<n;++i) scanf("%d %d",&u,&v),e[u].pb(v),e[v].pb(u);dfs(1,0);
	for(int i=0;i<n;++i) ans[i]=1ll*dp[1][i][1]*qPow(n,i<n-1?n-i-2:MOD-2)%MOD;
	for(int i=0,t;i<n;++i)
	{
		for(int j=i+1;j<n;++j)
			t=1ll*ans[j]*C[j][i]%MOD,ans[i]=add(ans[i],(j-i&1?MOD-t:t));
		printf("%d ",ans[i]);
	}return 0;
}