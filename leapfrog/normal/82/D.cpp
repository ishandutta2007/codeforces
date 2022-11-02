#include<bits/stdc++.h>
using namespace std;const int INF=1e9+5;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,a[1005],dp[1005][1005];
inline int wrkdp(int x,int y)
{
	if(y==n+1) return dp[x][y]=a[x];else if(y==n) return dp[x][y]=max(a[x],a[y]);
	if(dp[x][y]<INF) return dp[x][y];
	dp[x][y]=min(dp[x][y],max(a[x],a[y])+wrkdp(y+1,y+2));
	dp[x][y]=min(dp[x][y],max(a[x],a[y+1])+wrkdp(y,y+2));
	dp[x][y]=min(dp[x][y],max(a[y],a[y+1])+wrkdp(x,y+2));
	return dp[x][y];
}
inline void paint(int x,int y)
{
	if(y==n+1) printf("%d\n",x);else if(y==n) printf("%d %d\n",x,y);
	else if(dp[x][y]==max(a[x],a[y])+dp[y+1][y+2]) printf("%d %d\n",x,y),paint(y+1,y+2);
	else if(dp[x][y]==max(a[x],a[y+1])+dp[y][y+2]) printf("%d %d\n",x,y+1),paint(y,y+2);
	else if(dp[x][y]==max(a[y],a[y+1])+dp[x][y+2]) printf("%d %d\n",y,y+1),paint(x,y+2);
}
int main()
{
	read(n),memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++) read(a[i]);
	printf("%d\n",wrkdp(1,2));
	return paint(1,2),0;
}