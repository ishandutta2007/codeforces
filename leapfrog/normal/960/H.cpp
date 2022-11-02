//Coded by Kamiyama_Shiki on 2021.11.10 {{{
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
const int N=50005;int n,m,Q,cl[N];ll b[N],C;
struct node
{
	ll _0,_1,_2;
	node(ll w=-1,ll a=-1,ll b=-1)
	{
		if(~a) _0=w,_1=a,_2=b;
		else if(~w) _0=1,_1=w,_2=w*w;
		else _0=_1=_2=0;
	}
	inline node operator+(node a) {return node(_0+a._0,_1+a._1,_2+a._2);}
	inline node operator+(ll b) {return node(_0,_1+b*_0,_2+2*b*_1+_0*b*b);}
};
struct segm{int ls,rs;ll tg;char ed;node vl;}T[N*205];int tt,rt[N];
inline void pushup(int x) {T[x].vl=T[T[x].ls].vl+T[T[x].rs].vl;}
inline void newnd(int &x,node c) {T[x=++tt]=(segm){0,0,0,1,c};}
inline void allc(int x,ll w) {T[x].vl=T[x].vl+w,T[x].tg+=w;}
inline void pushdw(int x)
{
	if(T[x].ed)
	{
		ll lnr=T[x].vl._0>>1,lnl=T[x].vl._0-lnr;T[x].ed=0;
		newnd(T[x].ls,node(lnl,0,0)),newnd(T[x].rs,node(lnr,0,0));
	}
	if(T[x].tg) allc(T[x].ls,T[x].tg),allc(T[x].rs,T[x].tg),T[x].tg=0;
}
inline void modif(int x,int l,int r,int dl,int dr,int dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,dc);else pushdw(x);
	modif(T[x].ls,l,(l+r)>>1,dl,dr,dc),modif(T[x].rs,((l+r)>>1)+1,r,dl,dr,dc),pushup(x);
}
struct edge{int to,nxt;}e[N];int et,head[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
int dep[N],f[N],sz[N],sn[N],dfn[N],nfd[N],dt,tp[N];
inline void dfs0(int x,int fa)
{
	dep[x]=dep[f[x]=fa]+1,sz[x]=1,sn[x]=0;
	for(int i=head[x];i;i=e[i].nxt)
	{
		dfs0(e[i].to,x),sz[x]+=sz[e[i].to];
		if(sz[e[i].to]>sz[sn[x]]) sn[x]=e[i].to;
	}
}
inline void dfs1(int x,int top)
{
	dfn[x]=++dt,nfd[dt]=x,tp[x]=top;if(sn[x]) dfs1(sn[x],top);else return;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=sn[x]) dfs1(e[i].to,e[i].to);
}
inline void chang(int id,int x,int dc)
{
	for(;tp[x]!=1;x=f[tp[x]]) modif(rt[id],1,n,dfn[tp[x]],dfn[x],dc);
	modif(rt[id],1,n,1,dfn[x],dc);
}
inline void debug(int x,int l,int r)
{
	printf("[ %d %d ] : %lld %lld %lld\n",l,r,T[x].vl._0,T[x].vl._1,T[x].vl._2);
	if(l==r) return;else pushdw(x),debug(T[x].ls,l,(l+r)>>1),debug(T[x].rs,((l+r)>>1)+1,r);
}
int main()
{
	read(n,m,Q,C);for(int i=1;i<=n;i++) read(cl[i]);
	for(int i=2,f;i<=n;i++) read(f),adde(f,i);
	for(int i=1;i<=m;i++) read(b[i]),newnd(rt[i],(node){n,0,0});
	dfs0(1,0),dfs1(1,1);for(int i=1;i<=n;i++) chang(cl[i],i,1);
	for(int fg,x,y;Q--;)
	{
		read(fg,x);if(fg&1) {read(y),chang(cl[x],x,-1),chang(cl[x]=y,x,1);continue;}
		node w=T[rt[x]].vl;printf("%.8lf\n",1.0*w._2*b[x]*b[x]/n-2.0*C*b[x]/n*w._1+C*C);
	}return 0;
}