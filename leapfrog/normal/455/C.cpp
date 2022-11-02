//
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
struct edge{int to,nxt;}e[600005];
int n,m,q,et,head[300005],fa[300005],d[300005],mx,mxt,v[300005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void mrg(int x,int y) {int u=getf(x),v=getf(y);if(u^v) fa[u]=v;}
inline void dfs(int x,int rt,int dep)
{
	{if(v[x]==rt) return;else v[x]=rt;}if(mx<dep) mx=dep,mxt=x;
	for(int i=head[x];i;i=e[i].nxt) mrg(x,e[i].to),dfs(e[i].to,rt,dep+1);
}
int main()
{
	read(n),read(m),read(q);for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,x,y;i<=m;i++) read(x),read(y),adde(x,y),adde(y,x);
	for(int i=1;i<=n;i++) if(!v[i]) mx=0,mxt=i,dfs(i,i,0),mx=0,dfs(mxt,mxt,0),d[getf(i)]=mx;
	// for(int i=1;i<=n;i++) printf("%d%c",getf(i),i==n?'\n':' ');
	for(int fg,x,y;q--;)
	{
		read(fg),read(x);if(fg^1) read(y);
		if(fg^2) {printf("%d\n",d[getf(x)]);continue;}
		int u=getf(x),v=getf(y);if(!(u^v)) continue;else fa[v]=u;
		d[u]=max(max(d[u],d[v]),((d[u]+1)>>1)+((d[v]+1)>>1)+1);
	}
	return 0;
}