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
const int N=500005;struct edge{int to,w,nxt;}e[N<<1];int et=1,head[N],id[N],Ca,q[N];
int n,d[N],ds[N],sz[N],dfn[N],dt,nfd[N],rs[N];struct segm{int mx,mn,fg;}T[N<<2];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void allc(int x) {swap(T[x].mx,T[x].mn),T[x].mx=-T[x].mx,T[x].mn=-T[x].mn,T[x].fg^=1;}
inline void pushdw(int x) {if(T[x].fg) allc(x<<1),allc(x<<1|1),T[x].fg=0;}
inline void pushup(int x) {T[x].mx=max(T[x<<1].mx,T[x<<1|1].mx),T[x].mn=min(T[x<<1].mn,T[x<<1|1].mn);}
inline void build(int x,int l,int r)
{
	T[x].fg=0;if(l==r) return T[x].mx=T[x].mn=d[nfd[l]],void();
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),pushup(x);
}
inline void modif(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x);else pushdw(x);
	modif(x<<1,l,(l+r)>>1,dl,dr),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr),pushup(x);
}
inline void dfs0(int x,int fa)
{
	d[x]=d[fa]+1;for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs0(e[i].to,x);
}
inline void dfs1(int x,int fa)
{
	sz[x]=1,dfn[x]=++dt,nfd[dt]=x;for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
		ds[e[i].to]=ds[x]+e[i].w,dfs1(e[i].to,x),sz[x]+=sz[e[i].to],id[i>>1]=e[i].to;
}
inline void chg(int x) {x=id[x],modif(1,1,n,dfn[x],dfn[x]+sz[x]-1);}
inline void solve()
{
	int rt=0;for(int i=1;i<=n;i++) if(d[rt]<=d[i]) rt=i;
	dt=0,d[0]=-1,dfs0(rt,0),dfs1(rt,0),build(1,1,n);
	for(int i=1;i<n;i++) if(e[i<<1].w==1) chg(i);
	for(int i=1;i<=Ca;i++) chg(q[i]),rs[i]=max(rs[i],T[1].mx);
}
int main()
{
	read(n);for(int i=1,x,y,w;i<n;i++) read(x,y,w),adde(x,y,w),adde(y,x,w);
	dfs0(1,0);read(Ca);for(int i=1;i<=Ca;i++) read(q[i]);
	solve(),solve();for(int i=1;i<=Ca;i++) printf("%d\n",rs[i]);
	return 0;
}