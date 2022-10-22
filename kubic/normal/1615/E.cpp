#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define mid ((l+r)/2)
#define pb push_back
#define ll long long
int T,n,m,cnt,t,fa[N],dep[N],L[N],R[N],ord[N];ll ans;vector<int> e[N];
struct Seg {int mx,ps,tg;}sg[N*4];
void dfs(int u,int f)
{
	if(f) dep[u]=dep[f]+1;fa[u]=f;ord[L[u]=++L[0]]=u;
	for(auto v:e[u]) if(v!=f) dfs(v,u);R[u]=L[0];
}
void pu(int p)
{
	sg[p].mx=max(sg[p*2].mx,sg[p*2+1].mx);
	sg[p].ps=sg[p].mx==sg[p*2].mx?sg[p*2].ps:sg[p*2+1].ps;
}
void mdf(int p,int vl) {sg[p].mx+=vl;sg[p].tg+=vl;}
void pd(int p) {if(sg[p].tg) mdf(p*2,sg[p].tg),mdf(p*2+1,sg[p].tg),sg[p].tg=0;}
void build(int p,int l,int r)
{
	if(l==r) {sg[p]=(Seg) {dep[ord[l]],ord[l],0};return;}
	build(p*2,l,mid);build(p*2+1,mid+1,r);pu(p);
}
void upd(int p,int l,int r,int qL,int qR,int vl)
{
	if(l>=qL && r<=qR) {mdf(p,vl);return;}pd(p);
	if(qL<=mid) upd(p*2,l,mid,qL,qR,vl);if(qR>mid) upd(p*2+1,mid+1,r,qL,qR,vl);pu(p);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1,u,v;i<n;++i) scanf("%d %d",&u,&v),e[u].pb(v),e[v].pb(u);
	dfs(1,0);for(int i=2;i<=n;++i) if(e[i].size()<2) ++cnt;
	if(cnt<=m)
	{
		for(int i=cnt;i<=m;++i) ans=max(ans,1ll*i*(n-i));
		printf("%lld\n",ans);
	}
	else
	{
		ans=1e18;build(1,1,n);
		for(int i=1,u,w;i<=m;++i)
		{
			u=fa[sg[1].ps];w=sg[1].mx;t+=w;
			for(int j=1;j<=w;++j,u=fa[u]) upd(1,1,n,L[u],R[u],-1);
		}for(int i=0;i<=n-m-t;++i) ans=min(ans,1ll*(t+i)*(t+i+m*2-n));
		printf("%lld\n",ans);
	}return 0;
}