//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
#define Go(F,x,v) for(int v##i=F.head[x],v=F.e[v##i].to;v##i;v=F.e[v##i=F.e[v##i].nxt].to)
const int N=200005;struct Edge
{
	struct edge{int to,nxt;}e[N<<1];int et,head[N];
	inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
	inline void Adde(int x,int y) {adde(x,y),adde(y,x);}
}A,G;int n,m,q,cn,w[N];
namespace Kamiyama_Shiki/*{{{*/
{
	int dfn[N],low[N],dt,st[N],tp;
	inline void tarjan(int x)
	{
		dfn[x]=low[x]=++dt,st[++tp]=x;
		Go(A,x,y) if(!dfn[y])
		{
			tarjan(y),low[x]=min(low[x],low[y]);if(low[y]==dfn[x])
				{++cn;int z=-1;while(z^y) G.Adde(cn,z=st[tp--]);G.Adde(cn,x);}
		}else low[x]=min(low[x],dfn[y]);
	}
}/*}}}*/
namespace Tsumugi_Wenders/*{{{*/
{//
	int sz[N],sn[N],dep[N],fa[N],tp[N],dfn[N],nfd[N],dt,T[N<<2];multiset<int>son[N];
	inline void dfs0(int x,int f)
	{
		sz[x]=1,fa[x]=f,dep[x]=dep[f]+1;Go(G,x,y) if(y^f)
			{dfs0(y,x),sz[x]+=sz[y];if(sz[y]>sz[sn[x]]) sn[x]=y;}
	}
	inline void dfs1(int x,int top)
	{
		dfn[x]=++dt,nfd[dt]=x,tp[x]=top;if(sn[x]) dfs1(sn[x],top);
		Go(G,x,y) if(y^fa[x]&&y^sn[x]) dfs1(y,y);
	}
	inline void build(int x,int l,int r,int *a)
	{
		if(l==r) return T[x]=a[nfd[l]],void();
		build(x<<1,l,(l+r)>>1,a),build(x<<1|1,((l+r)>>1)+1,r,a),T[x]=min(T[x<<1],T[x<<1|1]);
	}
	inline void modif(int x,int l,int r,int dw,int dc)
	{
		if(l==r) return T[x]=dc,void();
		if(dw<=((l+r)>>1)) modif(x<<1,l,(l+r)>>1,dw,dc),T[x]=min(T[x<<1],T[x<<1|1]);
		else modif(x<<1|1,((l+r)>>1)+1,r,dw,dc),T[x]=min(T[x<<1],T[x<<1|1]);
	}
	inline int query(int x,int l,int r,int dl,int dr)
	{
		if(l>dr||dl>r) return 1e9;else if(dl<=l&&r<=dr) return T[x];
		return min(query(x<<1,l,(l+r)>>1,dl,dr),query(x<<1|1,((l+r)>>1)+1,r,dl,dr));
	}
	inline void ready()
	{
		dfs0(1,0),dfs1(1,1);
		for(int i=1;i<=n;i++) if(fa[i]) son[fa[i]].insert(w[i]);
		for(int i=n+1;i<=cn;i++) w[i]=*son[i].begin();
		build(1,1,cn,w);
	}
	inline void Updat(int x,int dc)
	{
		modif(1,1,cn,dfn[x],dc);if(!fa[x]) return w[x]=dc,void();
		int f=fa[x];son[f].erase(son[f].lower_bound(w[x])),son[f].insert(dc),w[x]=dc;
		if(w[f]!=*son[f].begin()) w[f]=*son[f].begin(),modif(1,1,cn,dfn[f],w[f]);
	}
	inline int Query(int x,int y)
	{
		int rs=1e9;while(tp[x]^tp[y])
		{
			if(dep[tp[x]]<dep[tp[y]]) swap(x,y);
			rs=min(rs,query(1,1,cn,dfn[tp[x]],dfn[x])),x=fa[tp[x]];
		}
		if(dfn[x]>dfn[y]) swap(x,y);
		rs=min(rs,query(1,1,cn,dfn[x],dfn[y]));
		if(fa[x]&&x>n) rs=min(rs,w[fa[x]]);
		return rs;
	}
}/*}}}*/
int main()
{
	read(n),read(m),read(q),cn=n;for(int i=1;i<=n;i++) read(w[i]);
	for(int i=1,x,y;i<=m;i++) read(x),read(y),A.Adde(x,y);
	Kamiyama_Shiki::tarjan(1),Tsumugi_Wenders::ready();
	for(int i=1,x,y;i<=q;i++)
	{
		char ch[5];scanf("%s",ch),read(x),read(y);
		if(*ch=='A') printf("%d\n",Tsumugi_Wenders::Query(x,y));
		else Tsumugi_Wenders::Updat(x,y);
	}
	return 0;
}