//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int N=200005;
struct edge{int to,nxt;}e[N<<1];
struct seg{int sm,val,lz;}t[N<<2];
int n,m,et,head[N],dt,a[N],fa[N],sz[N],dep[N],sn[N],tp[N],dfn[N],nfd[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void allc(int x,int c) {if(c) t[x].sm+=1ll*t[x].val*c,t[x].lz+=c;}
inline void up(int x) {t[x].sm=t[x<<1].sm+t[x<<1|1].sm,t[x].val=t[x<<1].val+t[x<<1|1].val;}
inline void down(int x) {allc(x<<1,t[x].lz),allc(x<<1|1,t[x].lz),t[x].lz=0;}
inline void build(int x,int l,int r)
{
	if(l==r) return(void)(t[x]=(seg){a[nfd[l]],dep[nfd[l]]&1?1:-1,0});
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),up(x);
}
inline void update(int x,int l,int r,int dl,int dr,int dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,dc);else down(x);
	update(x<<1,l,(l+r)>>1,dl,dr,dc),update(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),up(x);
}
inline int qrysm(int x,int l,int r,int dw)
{
	if(l==r) return t[x].sm;else down(x);
	if(dw<=((l+r)>>1)) return qrysm(x<<1,l,(l+r)>>1,dw);else return qrysm(x<<1|1,((l+r)>>1)+1,r,dw);
}
inline void dfs1(int x,int f)
{
	fa[x]=f,sz[x]=1,sn[x]=0,dep[x]=dep[f]+1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=f) {dfs1(e[i].to,x),sz[x]+=sz[e[i].to];if(sz[e[i].to]>sz[sn[x]]) sn[x]=e[i].to;}
}
inline void dfs2(int x,int top)
{
	tp[x]=top,dfn[x]=++dt,nfd[dt]=x;if(sn[x]) dfs2(sn[x],top);else return;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa[x]&&e[i].to!=sn[x]) dfs2(e[i].to,e[i].to);
}
inline void Chgson(int x,int c) {update(1,1,n,dfn[x],dfn[x]+sz[x]-1,dep[x]&1?c:-c);}
inline int Qryson(int x) {return qrysm(1,1,n,dfn[x]);}
int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	dfs1(1,0),dfs2(1,1),build(1,1,n);
	for(int fg,a,b;m--;) {read(fg),read(a);if(fg==1) read(b),Chgson(a,b);else printf("%d\n",Qryson(a));}
	return 0;
}