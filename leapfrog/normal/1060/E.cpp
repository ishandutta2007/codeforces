//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,nxt;}e[400005];
int n,et,head[200005],sz[200005],dep[200005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x,int fa)
{
	sz[x]=1,dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,x),sz[x]+=sz[e[i].to];
}
int main()
{
	read(n);
	for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	dep[0]=-1,dfs(1,0);long long ans=0,qwq=0;
	// for(int i=1;i<=n;i++) printf("%d , %d\n",sz[i],dep[i]);
	for(int i=1;i<=n;i++) {ans+=1ll*sz[i]*(n-sz[i]);if(dep[i]&1) ++qwq;}
	return printf("%lld\n",(ans+qwq*(n-qwq))>>1),0;
}