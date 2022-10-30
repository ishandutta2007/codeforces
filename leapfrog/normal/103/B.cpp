#include<bits/stdc++.h>
using namespace std;
struct edge{int to,nxt;}e[205];
int n,m,ct=0,et,head[105];char vis[105];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x) {for(int i=head[x];i;i=e[i].nxt) if(!vis[e[i].to]) vis[e[i].to]=1,dfs(e[i].to);}
int main()
{
	scanf("%d%d",&n,&m),memset(vis,0,sizeof(vis)),ct=0;
	for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),adde(x,y),adde(y,x);
	if(n!=m) return puts("NO"),0;else vis[1]=1,dfs(1);
	for(int i=1;i<=n;i++) ct+=vis[i];
	return ct==n?puts("FHTAGN!"):puts("NO"),0;
}