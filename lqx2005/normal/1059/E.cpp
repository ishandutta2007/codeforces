#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=100000;
const ll M=20;
ll n,l,s,ans;
ll w[N+5],par[N+5],f[M+5][N+5],dep[N+5],d[N+5],p2[M+5],sma[N+5];
vector<ll> g[N+5];
void dfs1(ll u,ll fa)
{
	par[u]=fa;
	dep[u]=dep[fa]+1;
	d[u]=d[fa]+w[u];
	f[0][u]=fa;
	for(ll i=1;p2[i]<=dep[u];i++) f[i][u]=f[i-1][f[i-1][u]];
	for(ll i=0;i<g[u].size();i++)
	{
		ll v=g[u][i];
		if(v==fa) continue;
		dfs1(v,u);
	}
	return;
}
ll jump(ll u)
{
	ll sum=s,len=l;
	for(ll i=M;i>=0;i--)
	{
		if(f[i][u]==0) continue;
		if(sum<d[u]-d[par[f[i][u]]]) continue;
		if(len<dep[u]-dep[par[f[i][u]]]) continue;
		sum-=d[u]-d[f[i][u]];
		len-=dep[u]-dep[f[i][u]];
		u=f[i][u];
	}
	if(w[u]>s) return -1;
	return u;
}
void init()
{
	memset(f,0,sizeof(f));
	p2[0]=1;
	for(ll i=1;i<=M;i++) p2[i]=p2[i-1]*2;
	dep[0]=-1;
	d[0]=0;
	dfs1(1,0);
	for(ll i=1;i<=n;i++) sma[i]=jump(i);
	return;
}
ll dfs2(ll u,ll fa)
{
	ll h=-1;
	for(ll i=0;i<g[u].size();i++)
	{
		ll v=g[u][i];
		if(v==fa) continue;
		ll now=dfs2(v,u);
		if(h==-1||dep[h]>dep[now]) h=now;
	}
	if(h==-1) 
	{
		ans++;
		return sma[u];
	}
	if(dep[h]<=dep[u]) return h;
	ans++;
	return sma[u];
}
int main()
{
	scanf("%lld%lld%lld",&n,&l,&s);
	for(ll i=1;i<=n;i++) scanf("%lld",&w[i]);
	ll v;
	for(ll i=2;i<=n;i++)
	{
		scanf("%lld",&v);
		g[i].push_back(v);
		g[v].push_back(i);
	}
	init();
	for(ll i=1;i<=n;i++) 
	{
		if(sma[i]==-1) 
		{
			printf("-1\n");
			return 0;
		}
	}
	ans=0;
	dfs2(1,0);
	printf("%lld\n",ans);
	return 0;
}