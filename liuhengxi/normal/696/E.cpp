// LUOGU_RID: 90472301
#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
typedef unsigned long long ull;
constexpr int N=1e5+5;
struct girl
{
	int num;ull wt;
	girl(){}
	girl(int n,ull w):num(n),wt(w){}
	friend bool operator<(girl u,girl v){return u.wt>v.wt;}
	friend girl operator+(girl u,ull v){return girl(u.num,~u.wt?u.wt+v:u.wt);}
};
namespace seg
{
	struct data
	{
		girl g;
		ull t;
	}s[(1<<18)+5];
#define lc (p<<1)
#define rc (p<<1|1)
#define g(p) s[p].g
#define t(p) s[p].t
	void build(int p,int l,int r,girl f(int))
	{
		if(r-l==1)return g(p)=f(l),void();
		int mid=(l+r)>>1;
		build(lc,l,mid,f);build(rc,mid,r,f);
		g(p)=max(g(lc),g(rc));
	}
	void update(int p,int l,int r,int x,int y,ull v)
	{
		if(x==l&&r==y)return g(p)=g(p)+v,t(p)+=v,void();
		int mid=(l+r)>>1;
		if(y<=mid)update(lc,l,mid,x,y,v);
		else if(mid<=x)update(rc,mid,r,x,y,v);
		else update(lc,l,mid,x,mid,v),update(rc,mid,r,mid,y,v);
		g(p)=max(g(lc),g(rc))+t(p);
	}
	void update(int p,int l,int r,int x,girl v)
	{
		if(r-l==1)return g(p)=v+t(p),void();
		int mid=(l+r)>>1;
		if(x<mid)update(lc,l,mid,x,v);
		else update(rc,mid,r,x,v);
		g(p)=max(g(lc),g(rc))+t(p);
	}
	girl query(int p,int l,int r,int x,int y)
	{
		if(x==l&&r==y)return g(p);
		int mid=(l+r)>>1;
		if(y<=mid)return query(lc,l,mid,x,y)+t(p);
		if(mid<=x)return query(rc,mid,r,x,y)+t(p);
		return max(query(lc,l,mid,x,mid),query(rc,mid,r,mid,y))+t(p);
	}
#undef g
#undef t
#undef lc
#undef rc
}
int n,m,q,siz[N],dfn[N],idfn[N],ind,hc[N],top[N],dep[N],fa[N];
vector<int> adj[N];
vector<girl> girls[N];
girl lightest(vector<girl> &g){return g.empty()?girl(-1,-1):*g.rbegin();}
void dfs1(int u,int f)
{
	siz[u]=1;hc[u]=-1;
	fa[u]=f;
	for(int v:adj[u])if(v!=fa[u])
	{
		dep[v]=dep[u]+1;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(!~hc[u]||siz[v]>siz[hc[u]])hc[u]=v;
	}
}
void dfs2(int u)
{
	idfn[dfn[u]=ind++]=u;
	if(~hc[u])top[hc[u]]=top[u],dfs2(hc[u]);
	for(int v:adj[u])if(v!=fa[u]&&v!=hc[u])dfs2(top[v]=v);
}
girl find_girl(int u,int v)
{
	girl ans(-1,-1);
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		ans=max(ans,seg::query(1,0,n,dfn[top[u]],dfn[u]+1));
		u=fa[top[u]];
	}
	if(dep[u]<dep[v])swap(u,v);
	ans=max(ans,seg::query(1,0,n,dfn[v],dfn[u]+1));
	return ans;
}
girl gf(int id){return lightest(girls[idfn[id]]);}
int c[N],g[N],gc;
int main()
{
	read(n,m,q);
	F(i,0,n-1)
	{
		int u,v;read(u,v);--u,--v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	F(i,0,m)
	{
		--read(c[i]);
		girls[c[i]].emplace_back(i,(ull)i<<17|c[i]);
	}
	dfs1(0,0);
	dfs2(0);
	F(i,0,n)sort(girls[i].begin(),girls[i].end());
	seg::build(1,0,n,gf);
	while(q--)
	{
		int opt;read(opt);
		if(opt==1)
		{
			int u,v,k;read(u,v,k);--u;--v;
			gc=0;
			while(gc<k)
			{
				g[gc]=find_girl(u,v).num;
				if(g[gc]==-1)break;
				girls[c[g[gc]]].pop_back();
				seg::update(1,0,n,dfn[c[g[gc]]],lightest(girls[c[g[gc]]]));
				++gc;
			}
			printf("%d ",gc);
			F(i,0,gc)printf("%d ",g[i]+1);
			puts("");
		}
		if(opt==2)
		{
			int u,x;read(u,x);--u;
			seg::update(1,0,n,dfn[u],dfn[u]+siz[u],(ull)x<<17);
		}
	}
	return 0;
}