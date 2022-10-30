#include<bits/stdc++.h>
using namespace std;
struct edge{int to,nxt;}e[800005];
int n,et,head[400005],dp[400005][2],sz[400005],r[400005],mxs[400005],wh[400005],dp2[400005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs1(int x,int fa)
{
	sz[x]=1,dp[x][0]=dp[x][1]=0;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs1(e[i].to,x),sz[x]+=sz[e[i].to];
	for(int i=head[x],w;i;i=e[i].nxt) if(e[i].to!=fa)
	{
		if(sz[e[i].to]>sz[mxs[x]]) mxs[x]=e[i].to;
		if(sz[e[i].to]<=n/2) w=sz[e[i].to];else w=dp[e[i].to][0];
		if(dp[x][0]<w) dp[x][1]=dp[x][0],dp[x][0]=w,wh[x]=e[i].to;else if(dp[x][1]<w) dp[x][1]=w;
	}
}
inline void dfs2(int x,int fa)
{
	r[x]=1;
	if(sz[mxs[x]]>n/2) r[x]=(sz[mxs[x]]-dp[mxs[x]][0]<=n/2);else if(n-sz[x]>n/2) r[x]=(n-sz[x]-dp2[x]<=n/2);
	for(int i=head[x],w;i;i=e[i].nxt) if(e[i].to!=fa)
	{
		if(n-sz[x]>n/2) w=dp2[x];else w=n-sz[x];
		dp2[e[i].to]=max(dp2[e[i].to],w);
		if(wh[x]==e[i].to) dp2[e[i].to]=max(dp2[e[i].to],dp[x][1]);else dp2[e[i].to]=max(dp2[e[i].to],dp[x][0]);
		dfs2(e[i].to,x);
	}
}
int main()
{
	scanf("%d",&n),et=0,memset(head,0,sizeof(head));
	for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),adde(x,y),adde(y,x);
	dfs1(1,0),dfs2(1,0);
	// for(int i=1;i<=n;i++) printf("%d%c",wh[i],i==n?'\n':' ');
	for(int i=1;i<=n;i++) printf("%d%c",r[i],i==n?'\n':' ');
	return 0;
}