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
struct edge{int to,w,nxt;}e[400005];int T,n,et,head[200005],sz[200005];long long ans;
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void dfs1(int x,int fa) {sz[x]=1;for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs1(e[i].to,x),sz[x]+=sz[e[i].to],ans+=(sz[e[i].to]&1)*e[i].w;}
inline void dfs2(int x,int fa) {for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs2(e[i].to,x),ans+=min(sz[e[i].to],n-sz[e[i].to])*1ll*e[i].w;}
int main()
{
	for(read(T);T--;)
	{
		read(n),n<<=1,et=0;for(register int i=1;i<=n;i++) head[i]=0;
		for(int i=1,x,y,w;i<n;i++) read(x),read(y),read(w),adde(x,y,w),adde(y,x,w);
		ans=0,dfs1(1,1),printf("%lld ",ans),ans=0,dfs2(1,1),printf("%lld\n",ans);
	}
	return 0;
}