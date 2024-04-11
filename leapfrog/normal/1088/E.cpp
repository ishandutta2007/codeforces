//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
struct edge{int to,nxt;}e[600005];int et,head[300005];
int n,a[300005],cnt;long long dp[300005],mx=-1e18;
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs1(int x,int fa)
{
	dp[x]=a[x];
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs1(e[i].to,x),dp[x]+=max(dp[e[i].to],0ll);
	mx=max(mx,dp[x]);
}
inline void dfs2(int x,int fa)
{
	dp[x]=a[x];
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs2(e[i].to,x),dp[x]+=max(dp[e[i].to],0ll);
	if(dp[x]==mx) dp[x]=-1e18,cnt++;
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	return dfs1(1,0),dfs2(1,0),printf("%lld %d\n",mx*cnt,cnt),0;
}