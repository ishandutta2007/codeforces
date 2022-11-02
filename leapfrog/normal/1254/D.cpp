//
#include<bits/stdc++.h>
using namespace std;const int P=998244353;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
const int N=150005;
struct edge{int to,nxt;}e[N<<1];
int n,q,et,head[N],sz[N],fa[N],sn[N],dep[N],dt,dfn[N],nfd[N],tp[N],T[N],tag[N];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void add(int x,int y) {if(x) for(;x<=n;x+=x&(-x)) (T[x]+=y)%=P;}
inline int qry(int x) {int r=0;for(;x;x-=x&(-x)) (r+=T[x])%=P;return r;}
inline void dfs1(int x,int f)
{
	dep[x]=dep[f]+1,fa[x]=f,sz[x]=1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=f)
	{
		dfs1(e[i].to,x),sz[x]+=sz[e[i].to];
		if(sz[e[i].to]>=sz[sn[x]]) sn[x]=e[i].to;
	}
}
inline void dfs2(int x,int top)
{
	dfn[x]=++dt,tp[x]=top;if(sn[x]) dfs2(sn[x],top);
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa[x]&&e[i].to!=sn[x]) dfs2(e[i].to,e[i].to);
}
inline void Chang(int x,int w)
{
	int gxs=P+1-1ll*ksm(n)*sz[sn[x]]%P,gxf=1ll*ksm(n)*sz[x]%P*w%P;(tag[x]+=w)%=P,gxs=1ll*gxs*w%P;
	add(dfn[sn[x]],gxs),add(dfn[sn[x]]+sz[sn[x]],P-gxs),add(dfn[x],w),add(dfn[x]+1,P-w);
	add(1,gxf),add(dfn[x],P-gxf),add(dfn[x]+sz[x],gxf),add(n+1,P-gxf);
}
inline int Query(int x)
{
	int res=0;res=qry(dfn[x]);
	while(x>1) x=tp[x],(res+=tag[fa[x]]*(P+1-1ll*ksm(n)*sz[x]%P)%P)%=P,x=fa[x];
	return res;
}
signed main()
{
	read(n),read(q);
	for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	dfs1(1,0),dfs2(1,1),memset(T,0,sizeof(T)),memset(tag,0,sizeof(tag));
	for(int i=1,fg,x,y;i<=q;i++) {read(fg),read(x);if(fg&1) read(y),Chang(x,y);else printf("%d\n",Query(x));}
	return 0;
}