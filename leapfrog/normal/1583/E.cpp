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
const int N=300005;int fr[N],tw[N],cf[N],tn[N],tt,dg[N];
struct edge{int to,nxt;}e[N<<1];int et,head[N],n,m,fa[N],f[N][20],dep[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline char mrg(int x,int y) {x=getf(x),y=getf(y);return x^y?fa[x]=y,1:0;}
inline void dfs0(int x,int fa)
{
	f[x][0]=fa,dep[x]=dep[fa]+1;for(int i=1;i<20;i++) f[x][i]=f[f[x][i-1]][i-1];
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs0(e[i].to,x);
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;~i;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	for(int i=19;~i;i--) if(f[x][i]^f[y][i]) x=f[x][i],y=f[y][i];
	return x^y?f[x][0]:x;
}
inline void dfs(int x,int fa) {for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,x),cf[x]^=cf[e[i].to];}
int main()
{
	read(n,m);for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,x,y;i<=m;i++) {read(x,y);if(mrg(x,y)) adde(x,y),adde(y,x);}
	int Q;read(Q);for(int i=1;i<=Q;i++) read(fr[i],tw[i]);
	for(int i=1;i<=Q;i++) {int x=fr[i],y=tw[i];cf[x]^=1,cf[y]^=1;}
	dfs0(1,0),dfs(1,0);int fg=0;for(int i=1;i<=n;i++) if(cf[i]) fg=1;
	if(fg)
	{
		int cnt=0;for(int i=2;i<=n;i++) dg[i]+=cf[i];
		for(int i=2;i<=n;i++) dg[f[i][0]]+=cf[i];
		for(int i=1;i<=n;i++) cnt+=(dg[i]&1);
		return puts("NO"),printf("%d\n",cnt>>1),0;
	}
	puts("YES");
	for(int i=1;i<=Q;i++)
	{
		tt=0;int x=fr[i],y=tw[i],lc=LCA(x,y),ds=dep[x]+dep[y]-dep[lc]*2;
		printf("%d\n",ds+1);while(x!=lc) printf("%d ",x),x=f[x][0];
		printf("%d ",lc),tt=0;while(y!=lc) tn[++tt]=y,y=f[y][0];
		for(int i=tt;i>=1;i--) printf("%d ",tn[i]);
		putchar('\n');
	}return 0;
}