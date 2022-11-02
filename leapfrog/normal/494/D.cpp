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
const int N=100005,P=1000000007;
struct $
{
	int _2,_1,_0;inline $(int x=0,int y=0,int z=0):_2(x),_1(y),_0(z){}
	inline $ operator+(int x) {return $((_2+2ll*_1*x+1ll*_0*x%P*x)%P,(_1+1ll*_0*x)%P,_0);}
	inline $ operator-(int x) {return (*this)+(x?P-x:x);}
	inline $ operator+($ x) {return $((_2+x._2)%P,(_1+x._1)%P,(_0+x._0)%P);}
	inline $ operator-($ x) {return $((_2-x._2+P)%P,(_1-x._1+P)%P,(_0-x._0+P)%P);}
}F[N],G[N];
struct edge{int to,w,nxt;}e[N<<1];int et,head[N],n,q;
int sz[N],sn[N],f[N],dep[N],tp[N],ds[N],sl[N];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void dfs0(int x,int fa)
{
	sz[x]=1,sn[x]=0,dep[x]=dep[fa]+1,f[x]=fa,F[x]._0=1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
	{
		dfs0(e[i].to,x),F[x]=(F[e[i].to]+e[i].w)+F[x];
		sz[x]+=sz[e[i].to];if(sz[e[i].to]>sz[sn[x]]) sn[x]=e[i].to;
	}
}
inline void dfs1(int x,int ls)
{
	G[x]=F[x]+(G[f[x]]-(F[x]+ls)+ls),ds[x]=(ds[f[x]]+ls)%P,sl[x]=ls;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=f[x]) dfs1(e[i].to,e[i].w);
}
inline void dfs2(int x,int top)
{
	tp[x]=top;if(sn[x]) dfs2(sn[x],top);else return;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to^f[x]&&e[i].to^sn[x]) dfs2(e[i].to,e[i].to);
}
inline int LCA(int x,int y)
{
	for(;tp[x]^tp[y];x=f[tp[x]]) if(dep[tp[x]]<dep[tp[y]]) swap(x,y);
	return dep[x]<dep[y]?x:y;
}
int main()
{
	read(n);for(int i=1,x,y,w;i<n;i++) read(x,y,w),adde(x,y,w),adde(y,x,w);
	dfs0(1,0),dfs2(1,1),G[0]=F[1],dfs1(1,0);
	//for(int i=1;i<=n;i++) printf("%d %d %d\n",F[i]._2,F[i]._1,F[i]._0);
	//for(int i=1;i<=n;i++) printf("%d %d %d\n",G[i]._2,G[i]._1,G[i]._0);
	read(q);for(int u,v,lc,d;q--;)
	{
		read(u,v),lc=LCA(u,v);
		if(lc==v) d=(ds[u]-ds[f[v]]+P)%P,printf("%lld\n",(G[u]._2-2ll*(G[f[v]]-(F[v]+sl[v])+d)._2+P*2)%P);
		else d=(ds[u]+ds[v]-2ll*ds[lc]+2*P)%P,printf("%lld\n",(2ll*(F[v]+d)._2-G[u]._2+P)%P);
	}return 0;
}