//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=300005;
namespace segment//{{{
{
	struct seg{char mx,lz;}T[N<<2];
	inline void allc(int x) {T[x].mx=T[x].lz=1;}
	inline void pushup(int x) {T[x].mx=T[x<<1].mx|T[x<<1|1].mx;}
	inline void pushdw(int x) {if(T[x].lz) allc(x<<1),allc(x<<1|1),T[x].lz=0;}
	inline void modif(int x,int l,int r,int dl,int dr)
	{
		if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x);else pushdw(x);
		modif(x<<1,l,(l+r)>>1,dl,dr),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr),pushup(x);
	}
	inline char query(int x,int l,int r,int dl,int dr)
	{
		if(l>dr||dl>r) return 0;else if(dl<=l&&r<=dr) return T[x].mx;else pushdw(x);
		return query(x<<1,l,(l+r)>>1,dl,dr)|query(x<<1|1,((l+r)>>1)+1,r,dl,dr);
	}
}using namespace segment;//}}}
struct edge{int to,w,nxt;}e[N<<1];int et,head[N],xr[N];
struct quer{int x,y,w,id;}q[N<<1];int n,Q,qt,fa[N];char rs[N<<1];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
int dep[N],f[N],sz[N],sn[N],dfn[N],nfd[N],tp[N],dt,we[N];
inline void dfs0(int x,int fa)//{{{
{
	dep[x]=dep[fa]+1,sz[x]=1,f[x]=fa,sn[x]=0;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
	{
		dfs0(e[i].to,x),sz[x]+=sz[e[i].to],we[e[i].to]=e[i].w;
		if(sz[e[i].to]>sz[sn[x]]) sn[x]=e[i].to;
	}
}
inline void dfs1(int x,int top)
{
	dfn[x]=++dt,nfd[dt]=x,tp[x]=top;if(sn[x]) dfs1(sn[x],top);
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=f[x]&&e[i].to!=sn[x]) dfs1(e[i].to,e[i].to);
}
inline char Check(int x,int y)
{
	while(tp[x]^tp[y])
	{
		if(dep[tp[x]]<dep[tp[y]]) swap(x,y);
		if(query(1,1,n+1,dfn[tp[x]],dfn[x])) return 1;else x=f[tp[x]];
	}
	if(dfn[x]>dfn[y]) swap(x,y);
	return query(1,1,n+1,dfn[x]+1,dfn[y]);
}
inline void Modif(int x,int y)
{
	while(tp[x]^tp[y])
	{
		if(dep[tp[x]]<dep[tp[y]]) swap(x,y);
		modif(1,1,n+1,dfn[tp[x]],dfn[x]),x=f[tp[x]];
	}
	if(dfn[x]>dfn[y]) swap(x,y);
	modif(1,1,n+1,dfn[x]+1,dfn[y]);
}
inline char Query(int x,int y)
{
	char rs=0;while(tp[x]^tp[y])
	{
		if(dep[tp[x]]<dep[tp[y]]) swap(x,y);
		rs^=xr[dfn[x]]^xr[dfn[tp[x]]-1],x=f[tp[x]];
	}
	if(dfn[x]>dfn[y]) swap(x,y);
	return rs^xr[dfn[x]]^xr[dfn[y]];
}//}}}
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
int main()
{
	read(n,Q);for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,x,y,w;i<=Q;i++)
	{
		read(x,y,w);int u=getf(x),v=getf(y);
		if(u^v) adde(x,y,w),adde(y,x,w),fa[u]=v,rs[i]=1;else q[++qt]=(quer){x,y,w,i};
	}
	for(int i=1;i<=n;i++) if(getf(i)==i) adde(n+1,i,0),adde(i,n+1,0);
	dfs0(n+1,0),dfs1(n+1,n+1);for(int i=1;i<=n;i++) xr[dfn[i]]=we[i];
	for(int i=1;i<=n+1;i++) xr[i]^=xr[i-1];
	for(int i=1;i<=qt;i++) if(!Check(q[i].x,q[i].y))
		if(Query(q[i].x,q[i].y)^q[i].w) rs[q[i].id]=1,Modif(q[i].x,q[i].y);
	for(int i=1;i<=Q;i++) puts(rs[i]?"YES":"NO");
	return 0;
}//1