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
struct edge{int to,w,nxt;}e[10005];
int n,m,et,head[105],dp[105][105][26];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline char dfs(int u,int v,int nw)
{
	if(~dp[u][v][nw]) return dp[u][v][nw];
	for(int i=head[u];i;i=e[i].nxt) if(e[i].w>=nw&&!dfs(v,e[i].to,e[i].w)) return dp[u][v][nw]=1;
	return dp[u][v][nw]=0;
}
int main()
{
	read(n),read(m),memset(dp,-1,sizeof(dp));
	for(int i=1,x,y;i<=m;i++) {char c;read(x),read(y),c=getchar(),adde(x,y,c-97);}
	for(int i=1;i<=n;i++,putchar('\n')) for(int j=1;j<=n;j++) printf("%c",66-dfs(i,j,0));
	return 0;
}