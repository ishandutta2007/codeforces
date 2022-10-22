#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=300000;
struct edge
{
	ll to,v;
};
vector<edge> g[N+5];
ll dp[N+5][2];
ll c[N+5];
ll n;
ll ans;

void dfs(ll u,ll fa)
{
	dp[u][0]=dp[u][1]=c[u];
	for(ll i=0;i<g[u].size();i++)
	{
		ll v=g[u][i].to;
		ll w=g[u][i].v;
		if(v==fa) continue;
		dfs(v,u);
		if(dp[v][0]+c[u]-w>dp[u][0]) dp[u][1]=dp[u][0],dp[u][0]=dp[v][0]+c[u]-w;
		else if(dp[v][0]+c[u]-w>dp[u][1]) dp[u][1]=dp[v][0]+c[u]-w;
	}
	ans=max(ans,dp[u][0]);
	ans=max(ans,dp[u][0]+dp[u][1]-c[u]);
	return;
}
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&c[i]);
	ll u,v,w;
	for(ll i=1;i<=n-1;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		g[u].push_back(edge{v,w});
		g[v].push_back(edge{u,w});
	}
	ans=-1;
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}