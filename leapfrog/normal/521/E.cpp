//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,nxt;}e[400005];int n,m,et,head[200005],st[200005],tp;
int dep[200005],fx[200005],fy[200005],fa[200005];char v[200005],is[200005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline int LCA(int x,int y) {for(;x^y;x=fa[x]) if(dep[x]<dep[y]) swap(x,y);return x;}
inline void ppath(int x,int y) {for(;x^y;x=fa[x]) st[++tp]=x;st[++tp]=y;}
inline void flush() {printf("%d ",tp);for(int i=1;i<=tp;i++) printf("%d%c",st[i],i==tp?'\n':' ');tp=0;}
inline void print(int a,int b,int c,int d)
{
	if(dep[b]>dep[d]) swap(a,c),swap(b,d);
	int e=LCA(a,c);puts("YES");
	//printf("%d %d %d %d %d\n",a,b,c,d,e);
	ppath(e,d),reverse(st+1,st+tp+1),flush();
	ppath(d,b),ppath(a,e),flush();
	st[++tp]=d,ppath(c,e),flush(),exit(0);
}
inline void dfs(int x)
{
	dep[x]=dep[fa[x]]+1,v[x]=is[x]=1;
	for(int i=head[x],y=e[i].to;i;y=e[i=e[i].nxt].to) if(y^fa[x])
	{
		if(!v[y]) {fa[y]=x,dfs(y);continue;}
		if(is[y]) {for(int u=x;u^y;u=fa[u]) if(fx[u]) print(fx[u],fy[u],x,y);else fx[u]=x,fy[u]=y;}
	}is[x]=0;
}
int main()
{
	read(n),read(m);for(int i=1,x,y;i<=m;i++) read(x),read(y),adde(x,y),adde(y,x);
	for(int i=1;i<=n;i++) if(!v[i]) dfs(i);
	return puts("NO"),0;
}