#include <bits/stdc++.h>
using namespace std;
#define N 400005
#define ll long long
#define pb push_back
int n,cntV,ans;bool vs[N],tg[N];
struct Edge {int u,v,w;}a[N];
vector<int> vc[N];vector<Edge> e[N];
struct Frac
{
	ll x,y;
	bool operator < (Frac t) const
	{return x==t.x?y<t.y:x<t.x;}
};map<Frac,int> id;
ll gcd(ll x,ll y) {return y?gcd(y,x%y):x;}
void addE(Frac u1,Frac v1,int w)
{
	if(!id.count(u1)) id[u1]=++cntV;
	if(!id.count(v1)) id[v1]=++cntV;
	int u=id[u1],v=id[v1];tg[u]^=1;a[w]=(Edge) {u,v,0};
	e[u].pb((Edge) {u,v,w});e[v].pb((Edge) {v,u,w});
}
void dfs(int u)
{
	if(vs[u]) return;vs[u]=1;
	for(auto i:e[u])
	{
		int v=i.v,w=i.w;if(vs[v]) continue;dfs(v);
		if(tg[v]) tg[u]^=1,a[w].w^=1;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		ll d;Frac x,y,u,v;
		scanf("%lld %lld %lld %lld",&x.x,&x.y,&y.x,&y.y);
		u=(Frac) {(x.x+x.y)*y.y,x.y*y.x};
		d=gcd(u.x,u.y);u.x/=d;u.y/=d;
		v=(Frac) {x.x*y.y,x.y*(y.x+y.y)};
		d=gcd(v.x,v.y);v.x/=d;v.y/=d;addE(u,v,i);
	}for(int i=1;i<=cntV;++i) if(!vs[i]) dfs(i);
	for(int i=1;i<=n;++i) vc[a[i].w?a[i].v:a[i].u].pb(i);
	for(int i=1;i<=cntV;++i) ans+=vc[i].size()/2;
	printf("%d\n",ans);
	for(int i=1;i<=cntV;++i)
		for(int j=1;j<vc[i].size();j+=2)
			printf("%d %d\n",vc[i][j-1],vc[i][j]);
	return 0;
}