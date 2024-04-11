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
int n,et,head[200005];struct edge{int to,nxt;}e[400005];
ll f[200005],g[200005];int sz[200005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs1(int x,int fa)
{
	sz[x]=1,g[x]=0;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs1(e[i].to,x),sz[x]+=sz[e[i].to],g[x]+=g[e[i].to];
	g[x]+=sz[x];
}
inline void dfs2(int x,int fa)
{
	f[x]=f[fa]+n-2*sz[x];
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs2(e[i].to,x);
}
int main()
{
	read(n);for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	dfs1(1,0),f[1]=g[1];for(int i=head[1];i;i=e[i].nxt) dfs2(e[i].to,1);
	ll mx=0;for(int i=1;i<=n;i++) mx=max(mx,f[i]);
	return printf("%lld\n",mx),0;
}