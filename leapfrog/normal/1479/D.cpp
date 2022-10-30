//Coded by Kamiyama_Shiki on 2021.11.09 {{{
//
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
typedef unsigned long long ull;mt19937_64 myrand(114);
const int N=300005;int n,m,a[N],rt[N];ull cv[N];
namespace zzt
{
	struct seg{int ls,rs;ull xr;}T[6300005];int tt;
	inline void build(int &x,int y,int l,int r,int dw,ull dc)
	{
		T[x=++tt]=T[y],T[x].xr^=dc;if(l==r) return;
		if(dw<=((l+r)>>1)) build(T[x].ls,T[y].ls,l,(l+r)>>1,dw,dc);
		else build(T[x].rs,T[y].rs,((l+r)>>1)+1,r,dw,dc);
	}
	inline int qry(int x,int y,int z,int w,int l,int r,int dl,int dr)
	{
		if(l>dr||dl>r||!(T[x].xr^T[y].xr^T[z].xr^T[w].xr)) return -1;else if(l==r) return l;
		int v;if(~(v=qry(T[x].ls,T[y].ls,T[z].ls,T[w].ls,l,(l+r)>>1,dl,dr))) return v;
		return qry(T[x].rs,T[y].rs,T[z].rs,T[w].rs,((l+r)>>1)+1,r,dl,dr);
	}
}
struct edge{int to,nxt;}e[N<<1];int et,head[N];
int dep[N],sn[N],sz[N],f[N],tp[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs0(int x,int fa)
{
	dep[x]=dep[f[x]=fa]+1,sz[x]=1,sn[x]=0;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
	{
		dfs0(e[i].to,x),sz[x]+=sz[e[i].to];
		if(sz[e[i].to]>sz[sn[x]]) sn[x]=e[i].to;
	}
}
inline void dfs1(int x,int top)
{
	tp[x]=top;if(sn[x]) dfs1(sn[x],top);else return;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=f[x]&&e[i].to!=sn[x]) dfs1(e[i].to,e[i].to);
}
inline void dfs2(int x,int fa)
{
	zzt::build(rt[x],rt[fa],1,n,a[x],cv[a[x]]);
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs2(e[i].to,x);
}
inline int LCA(int x,int y)
{
	for(;tp[x]^tp[y];x=f[tp[x]]) if(dep[tp[x]]<dep[tp[y]]) swap(x,y);
	return dep[x]<dep[y]?x:y;
}
int main()
{
	read(n,m);for(int i=1;i<=n;i++) read(a[i]),cv[i]=myrand();
	for(int i=1,x,y;i<n;i++) read(x,y),adde(x,y),adde(y,x);
	dfs0(1,0),dfs1(1,1),dfs2(1,0);
	for(int i=1,x,y,l,r;i<=m;i++)
	{
		read(x,y,l,r);int lc=LCA(x,y);
		printf("%d\n",zzt::qry(rt[x],rt[y],rt[lc],rt[f[lc]],1,n,l,r));
	}return 0;
}