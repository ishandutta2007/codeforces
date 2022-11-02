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
struct edge{int to,nxt;}e[300005];
int n,Q,et,head[300005],sz[300005],zx[300005],sn[300005],fa[300005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x)
{
	sz[x]=1,sn[x]=0;
	for(int i=head[x];i;i=e[i].nxt) dfs(e[i].to),sz[x]+=sz[e[i].to],sn[x]=sz[e[i].to]>sz[sn[x]]?e[i].to:sn[x];
	if(!sn[x]||sz[x]>=sz[sn[x]]*2) return(void)(zx[x]=x);
	int y=zx[sn[x]];while(x!=y&&(sz[x]-sz[y])*2>sz[x]) y=fa[y];zx[x]=y;
}
int main()
{
	read(n),read(Q);for(int i=2;i<=n;i++) read(fa[i]),adde(fa[i],i);
	sz[0]=0,dfs(1);for(int x;Q--;) read(x),printf("%d\n",zx[x]);
	return 0;
}