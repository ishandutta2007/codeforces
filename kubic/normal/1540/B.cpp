#include <bits/stdc++.h>
using namespace std;
#define N 205
#define MOD 1000000007
#define pb push_back
const int inv2=500000004;
int n,ans,L[N],R[N],ord[N],dep[N],dp[N][N];vector<int> e[N];
int qPow(int x,int y)
{
	int res=1;
	for(;y;y/=2,x=1ll*x*x%MOD) if(y&1)
		res=1ll*res*x%MOD;return res;
}
void W(int u,int v,int lca)
{
	if(u<v) swap(u,v);
	ans=(ans+dp[dep[u]-dep[lca]][dep[v]-dep[lca]])%MOD;
}
void dfs(int u,int f)
{
	ord[L[u]=++L[0]]=u;dep[u]=dep[f]+1;
	for(auto v:e[u]) if(v!=f)
	{
		dfs(v,u);
		for(int j=L[u]+1;j<L[v];++j)
			for(int k=L[v];k<=R[v];++k) W(ord[j],ord[k],u);
	}R[u]=L[0];for(int i=L[u]+1;i<=R[u];++i) if(u>ord[i]) ++ans; 
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
		scanf("%d %d",&u,&v),e[u].pb(v),e[v].pb(u);
	for(int i=1;i<=n;++i) dp[0][i]=1;
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j)
		dp[i][j]=1ll*(dp[i-1][j]+dp[i][j-1])*inv2%MOD;
	for(int i=1;i<=n;++i) L[0]=0,dfs(i,0);
	printf("%lld\n",1ll*ans*qPow(n,MOD-2)%MOD);return 0;
}