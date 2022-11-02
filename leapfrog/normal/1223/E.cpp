// 
//  
// 
//  
//   
#include<bits/stdc++.h>
// #define int long long
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
using namespace std;
struct edge{int to,w,nxt;}e[1000005];
int Q,n,k,et,head[500005],cnt;char vis[500005];long long dp[500005][2];pair<int,int>v[500005];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline int read()
{
	register int t=0;register char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar()) t=(t<<1)+(t<<3)+(c^48);
	return t;
}
inline void dfs(int x,int fa=0)
{
	int fla=0;for(register int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,x),fla=1;
	if(!fla) return;else cnt=0;
	for(register int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) v[++cnt]=make_pair(dp[e[i].to][1]+e[i].w-dp[e[i].to][0],e[i].to);
	sort(v+1,v+cnt+1,greater<pair<int,int> >());
	for(register int i=1;i<=min(k,cnt);i++)
	{
		if(v[i].first<=0) break;
		dp[x][0]+=v[i].first+dp[v[i].second][0],vis[v[i].second]=1;
		if(i!=k) dp[x][1]+=v[i].first+dp[v[i].second][0];
	}
	if(k<=cnt&&vis[v[k].second]) dp[x][1]+=dp[v[k].second][0];
	for(register int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa&&!vis[e[i].to]) dp[x][0]+=dp[e[i].to][0],dp[x][1]+=dp[e[i].to][0];
}
signed main()
{
	for(Q=read();Q--;)
	{
		n=read(),k=read(),et=0;
		for(register int i=1;i<=n;i++) head[i]=vis[i]=dp[i][0]=dp[i][1]=0;
		for(register int i=1,x,y,w;i<n;i++) x=read(),y=read(),w=read(),adde(x,y,w),adde(y,x,w);
		long long r=0;dfs(1);for(int i=1;i<=n;i++) r=max(r,max(dp[i][1],dp[i][0]));
		printf("%lld\n",r);
	}
	return 0;
}