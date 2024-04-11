#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=100000;
struct edge
{
	ll to,v;
};
struct BIT
{
	ll t[N*10+5],maxt;
	ll lowbit(ll x)
	{
		return x&(-x);
	}
	void add(ll x,ll v)
	{
		for(ll i=x;i<=maxt;i+=lowbit(i)) t[i]+=v;
		return;
	}
	ll sum(ll x)
	{
		ll ans=0;
		for(ll i=x;i>=1;i-=lowbit(i)) ans+=t[i];
		return ans;
	}
}cost,food;
ll n,T,maxt;
ll x[N+5],t[N+5],d[N+5],ans[N+5],dp[N+5];
vector<edge> g[N+5];
void add(ll u,ll v,ll w)
{
	g[u].push_back(edge{v,w});
	g[v].push_back(edge{u,w});
	return;
}
void dfs1(ll u,ll fa,ll dis)
{
	d[u]=d[fa]+dis;
	food.add(t[u],x[u]);
	cost.add(t[u],x[u]*t[u]);
	ll l=1,r=maxt,best=maxt+1;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(cost.sum(mid)+d[u]*2>T) best=mid,r=mid-1;
		else l=mid+1; 
	}
	dp[u]=food.sum(best-1);
	if(best<=maxt) dp[u]+=(T-d[u]*2-cost.sum(best-1))/best;	
	for(ll i=0;i<g[u].size();i++)
	{
		ll v=g[u][i].to;
		ll w=g[u][i].v;
		if(v==fa) continue;
		dfs1(v,u,w);
	}
	food.add(t[u],-x[u]);
	cost.add(t[u],-x[u]*t[u]);	
	return;
}
void dfs2(ll u,ll fa)
{
	ans[u]=dp[u];
	ll maxf=-1,maxs=-1;
	for(ll i=0;i<g[u].size();i++)
	{
		ll v=g[u][i].to;
		if(v==fa) continue;
		dfs2(v,u);
		if(ans[v]>maxf) maxs=maxf,maxf=ans[v];
		else if(ans[v]>maxs) maxs=ans[v];
	}
	if(u==1) ans[u]=max(ans[u],maxf);
	else ans[u]=max(ans[u],maxs);
	return;
}
int main()
{
	scanf("%lld%lld",&n,&T);
	maxt=-1;
	for(ll i=1;i<=n;i++) scanf("%lld",&x[i]);
	for(ll i=1;i<=n;i++) scanf("%lld",&t[i]),maxt=max(maxt,t[i]);
	cost.maxt=maxt;
	food.maxt=maxt;
	ll v,w;
	for(ll i=2;i<=n;i++) 
	{
		scanf("%lld%lld",&v,&w);
		add(i,v,w);
	}
	dfs1(1,0,0);
	dfs2(1,0);
	printf("%lld\n",ans[1]);
    return 0;
}