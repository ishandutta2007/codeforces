#include <bits/stdc++.h>
using namespace std;
#define N 305
#define MOD 998244353
#define set(a,vl) memset(a,vl,sizeof(a))
#define pb push_back 
int n,ans,dep[N],mx[N],tmp1[N],tmp2[N],w[N],dp1[N][N],dp2[N][N];
bool tg[N];vector<int> e[N];
void W(int &x,int y) {x=(x+y)%MOD;}
int qPow(int x,int y)
{
	int res=1;
	for(;y;y/=2,x=1ll*x*x%MOD) if(y&1)
		res=1ll*res*x%MOD;return res;
}
void slv(int u,int v,int x)
{
	if(!tg[u])
	{
		tg[u]=1;mx[u]=max(mx[u],mx[v]);
		for(int i=dep[u];i<=mx[u];++i)
			dp1[u][i]=dp1[v][i],dp2[u][i]=dp2[v][i];
		if(dep[u]+x<mx[u])
			dp1[u][dep[u]]=dp2[u][dep[u]+x+1],dp2[u][dep[u]+x+1]=0;
		return;
	}set(tmp1,0);set(tmp2,0);
	for(int i=dep[u];i<=mx[u];++i) for(int j=dep[u];j<=mx[v];++j)
	{
		W(tmp1[max(i,j)],1ll*dp1[u][i]*dp1[v][j]%MOD);
		if(i+j-dep[u]*2<=x)
		{
			W(tmp2[j],1ll*dp1[u][i]*dp2[v][j]%MOD);
			W(tmp2[i],1ll*dp2[u][i]*dp1[v][j]%MOD);
		}
		else
		{
			W(tmp1[i],1ll*dp1[u][i]*dp2[v][j]%MOD);
			W(tmp1[j],1ll*dp2[u][i]*dp1[v][j]%MOD);
		}W(tmp2[min(i,j)],1ll*dp2[u][i]*dp2[v][j]%MOD);
	}mx[u]=max(mx[u],mx[v]);
	for(int i=dep[u];i<=mx[u];++i) dp1[u][i]=tmp1[i],dp2[u][i]=tmp2[i];
}
void dfs(int u,int f,int x)
{
	dep[u]=mx[u]=dep[f]+1;tg[u]=0;
	if(f && e[u].size()<2) dp1[u][dep[u]]=1;
	for(int i=0,v;i<e[u].size();++i)
	{v=e[u][i];if(v!=f) dfs(v,u,x),slv(u,v,x);}
	for(int i=dep[u];i<=mx[u];++i)
	{
		if(i>dep[u]) W(dp2[u][dep[u]],dp2[u][i]); 
		if(i<=dep[u]+x) W(dp2[u][dep[u]],dp1[u][i]);
		else W(dp1[u][i],dp1[u][i]);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i) scanf("%d %d",&u,&v),e[u].pb(v),e[v].pb(u);
	for(int i=1;i<=n;++i)
	{
		set(dp1,0);set(dp2,0);dfs(1,0,i);
		for(int j=1;j<=i+1;++j) W(w[i],dp2[1][j]);
	}for(int i=1;i<n;++i) W(ans,1ll*(w[i+1]-w[i])*i%MOD);
	printf("%lld\n",1ll*(ans+n-1+MOD)*qPow(2,MOD-n-1)%MOD);return 0;
}