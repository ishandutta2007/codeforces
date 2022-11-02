//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
ll dp[5005][5005][2];//i th node with its subtree choose j things,with or without coupon
struct edge{int to,nxt;}e[5005];int n,B,v[5005],d[5005],et,head[5005],sz[5005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x)
{
	dp[x][0][0]=0,dp[x][1][0]=v[x],dp[x][1][1]=v[x]-d[x],sz[x]=1;
	for(int i=head[x];i;sz[x]+=sz[e[i].to],i=e[i].nxt)
	{
		dfs(e[i].to);for(int j=sz[x];j>=0;j--) for(int k=1;k<=sz[e[i].to];k++)
			dp[x][j+k][0]=min(dp[x][j][0]+dp[e[i].to][k][0],dp[x][j+k][0]),
			dp[x][j+k][1]=min(dp[x][j][1]+dp[e[i].to][k][1],dp[x][j+k][1]),
			dp[x][j+k][1]=min(dp[x][j][1]+dp[e[i].to][k][0],dp[x][j+k][1]);
	}
	//printf("%d : ",x);for(int i=1;i<=sz[x];i++) printf("<%lld,%lld>%c",dp[x][i][0],dp[x][i][1],i==sz[x]?'\n':' ');
}
int main()
{
	read(n),read(B),read(v[1]),read(d[1]),memset(dp,0x3f,sizeof(dp));
	for(int i=2,f;i<=n;i++) read(v[i]),read(d[i]),read(f),adde(f,i);
	dfs(1);for(int i=n;i>=0;i--) if(dp[1][i][0]<=B||dp[1][i][1]<=B) return printf("%d\n",i),0;
	return 0;
}