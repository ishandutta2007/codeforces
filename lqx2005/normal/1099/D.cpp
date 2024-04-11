#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=100000;
const ll INF=100000000000;
ll n;
vector<ll> g[N+5];
ll s[N+5],m[N+5],a[N+5];
bool flag;
void dfs1(ll u,ll fa)
{
	ll maxdep=INF;
	for(ll i=0;i<g[u].size();i++)
	{
		ll v=g[u][i];
		if(v==fa) continue;
		dfs1(v,u);
		maxdep=min(maxdep,m[v]);
	}
	if(s[u]!=-1) maxdep=min(maxdep,s[u]);
	m[u]=maxdep;
	return;
}
void dfs2(ll u,ll fa)
{
	if(m[u]==INF) return;
	if(s[u]==-1) s[u]=m[u];
	a[u]=s[u]-s[fa]; 
	if(a[u]<0||s[u]>m[u]) 
	{
		flag=1;
		return;
	}
	for(ll i=0;i<g[u].size();i++)
	{
		ll v=g[u][i];
		if(v==fa) continue;
		dfs2(v,u);
		if(flag) return;
	}	
	return;
}
int main()
{
	scanf("%lld",&n);
	for(ll i=2;i<=n;i++) 
	{
		ll v;
		scanf("%lld",&v);
		g[i].push_back(v);
		g[v].push_back(i);
	}
	for(ll i=1;i<=n;i++) scanf("%lld",&s[i]);
	dfs1(1,0);
	flag=0;
	dfs2(1,0);
	if(flag)
	{
		printf("-1\n");
		return 0;
	}
	ll ans=0;
	for(ll i=1;i<=n;i++) ans+=a[i];
	printf("%lld\n",ans);
	return 0;
}