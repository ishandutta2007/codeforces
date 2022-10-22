#include <bits/stdc++.h>
using namespace std;
#define N 2005
#define ll long long
#define pb push_back
int T,n,m,S,a[N],b[N],U[N],V[N],fa[N],pr[N];
ll l,r,s;bool fl,vs[N],tg[N];
struct Edge {int v,id;};vector<Edge> e[N];
int findRt(int u) {return u==fa[u]?u:fa[u]=findRt(fa[u]);}
bool merge(int u,int v)
{u=findRt(u);v=findRt(v);if(u==v) return 0;fa[u]=v;return 1;}
void dfs(int u,int f,int fe,ll nw)
{
	if(s) return;
	if(pr[u])
	{
		for(int i=u;i;i=pr[i]) if(merge(i,1)) s+=b[i];
		for(int i=f;i;i=pr[i]) if(merge(i,1)) s+=b[i];
	}if(s) return;vs[u]=tg[u]=1;pr[u]=f;
	for(auto i:e[u]) if(i.id!=fe && nw>a[i.v])
	{
		if(vs[i.v])
		{for(int j=u;j;j=pr[j]) if(merge(j,1)) s+=b[j];break;}
		dfs(i.v,u,i.id,nw+b[i.v]);
	}vs[u]=0;
}
bool chk(ll x)
{
	for(int i=1;i<=n;++i) fa[i]=i;
	while(1)
	{
		for(int i=1;i<=n;++i) pr[i]=tg[i]=0,e[i].clear();
		for(int i=1,u,v;i<=m;++i)
		{
			u=findRt(U[i]);v=findRt(V[i]);
			if(u!=v) e[u].pb((Edge) {v,i}),e[v].pb((Edge) {u,i});
		}S=findRt(1);s=0;dfs(S,0,0,x);if(s) {x+=s;continue;}
		for(int i=1;i<=n;++i)
			if(i==findRt(i) && !tg[i]) return 0;return 1;
	}return 1;
}
void slv()
{
	scanf("%d %d",&n,&m);l=0;r=1e15;
	for(int i=2;i<=n;++i) scanf("%d",&a[i]);
	for(int i=2;i<=n;++i) scanf("%d",&b[i]);
	for(int i=1;i<=m;++i) scanf("%d %d",&U[i],&V[i]);
	while(l<=r) {ll mid=(l+r)/2;if(chk(mid)) r=mid-1;else l=mid+1;}
	printf("%lld\n",l);
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}