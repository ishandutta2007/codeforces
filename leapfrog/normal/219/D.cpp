#include<bits/stdc++.h>
using namespace std;
struct edge{int to,w,nxt;}e[400005];
int n,et,head[200005],s[200005],d[200005],dp[200005];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void dfs1(int x,int fa)
{
	d[x]=0,s[x]=1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs1(e[i].to,x),d[x]+=e[i].w+d[e[i].to],s[x]+=s[e[i].to];
}
inline void dfs2(int x,int fa,int ls)
{
	dp[x]=dp[fa]+(ls?1:-1);
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs2(e[i].to,x,e[i].w^1);
}
int main()
{
	scanf("%d",&n),et=0,memset(head,0,sizeof(head));
	for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),adde(x,y,0),adde(y,x,1);
	dfs1(1,0),dp[0]=d[1]+1,dfs2(1,0,0);int r=n+1;
	for(int i=1;i<=n;i++) r=min(r,dp[i]);
	printf("%d\n",r);for(int i=1;i<=n;i++) if(r==dp[i]) printf("%d ",i);
	return puts(""),0;
}