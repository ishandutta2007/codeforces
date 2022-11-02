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
int et,head[100005];struct edge{int to,nxt;}e[200005];
int n,rt,dep[100005],dt,nfd[100005],sz[100005],f[100005],mt[100005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs0(int x,int fa)
{
	sz[x]=1;for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs0(e[i].to,x),sz[x]+=sz[e[i].to],f[x]=max(f[x],sz[e[i].to]);
	f[x]=max(f[x],n-sz[x]);if(f[x]<=f[rt]) rt=x;
}
inline void dfs1(int x,int fa)
{
	nfd[++dt]=x,dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs1(e[i].to,x);
}
int main()
{
	read(n);for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	rt=0,f[0]=1e9,dfs0(1,0),dep[0]=-1,dfs1(rt,0);ll res=0;
	for(int i=1,e=n>>1,u,v;i<=e;i++) u=nfd[i],v=nfd[i+e],mt[u]=v,mt[v]=u,res+=(dep[u]+dep[v])<<1;
	if(n&1) {int u=nfd[1],v=nfd[n/2+1],w=nfd[n];mt[u]=v,mt[v]=w,mt[w]=u,res+=dep[w]<<1;}
	printf("%lld\n",res);for(int i=1;i<=n;i++) printf("%d%c",mt[i],i==n?'\n':' ');
	return 0;
}