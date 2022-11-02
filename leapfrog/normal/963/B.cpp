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
struct edge{int to,nxt;}e[400005];
int rt,n,et,head[200005],sz[200005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs1(int x) {sz[x]=1;for(int i=head[x];i;i=e[i].nxt) dfs1(e[i].to),sz[x]+=sz[e[i].to];}
inline void dfs2(int x)
{
	for(int i=head[x];i;i=e[i].nxt) if((sz[e[i].to]&1)^1) dfs2(e[i].to);
	printf("%d\n",x);
	for(int i=head[x];i;i=e[i].nxt) if(sz[e[i].to]&1) dfs2(e[i].to);
}
int main()
{
	read(n);if(n&1) et=0,memset(head,0,sizeof(head));else return puts("NO"),0;
	for(int i=1,f;i<=n;i++) {read(f);if(f) adde(f,i);else rt=i;}
	return puts("YES"),dfs1(rt),dfs2(rt),0;
}