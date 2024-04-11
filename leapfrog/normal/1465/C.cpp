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
int T,n,m,et,head[100005];char vis[100005];struct edge{int to,nxt;}e[200005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline char dfs(int x,int rt)
{
	vis[x]=1;
	for(int i=head[x];i;i=e[i].nxt) if(!vis[e[i].to]) return dfs(e[i].to,rt);else if(e[i].to==rt) return 1;
	return 0;
}
int main()
{
	for(read(T);T--;)
	{
		et=0,memset(head,0,sizeof(head)),read(n),read(m),memset(vis,0,sizeof(vis));
		int fc=0;for(int x,y,i=1;i<=m;i++) {read(x),read(y);if(x==y) fc++;else adde(x,y);}
		for(int i=1;i<=n;i++) if(!vis[i]) m+=dfs(i,i);
		printf("%d\n",m-fc);
	}
	return 0;
}