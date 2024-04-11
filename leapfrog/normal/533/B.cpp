//
//
#include<bits/stdc++.h>
using namespace std;const int P=1e9+7;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,nxt;}e[400005];
int rt,n,et,head[200005],a[200005];long long dp[200005][2];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x)
{
	dp[x][0]=0,dp[x][1]=-1e9;
	for(int i=head[x];i;i=e[i].nxt)
	{
		dfs(e[i].to);long long _0=dp[x][0],_1=dp[x][1];
		dp[x][0]=max(dp[e[i].to][0]+_0,dp[e[i].to][1]+_1);
		dp[x][1]=max(dp[e[i].to][0]+_1,dp[e[i].to][1]+_0);
	}
	dp[x][1]=max(dp[x][1],dp[x][0]+a[x]);
}
int main()
{
	read(n);for(int i=1,f;i<=n;i++) {read(f),read(a[i]);if(~f) adde(f,i);else rt=i;}
	return dfs(rt),printf("%lld\n",max(dp[rt][0],dp[rt][1])),0;
}