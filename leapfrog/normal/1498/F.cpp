//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,K,a[100005],dp[100005][45],tmp[45],res;
struct edge{int to,nxt;}e[200005];int et,head[100005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs1(int x,int fa)
{
	dp[x][0]=a[x];for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
		{dfs1(e[i].to,x);for(int j=0;j<2*K;j++) dp[x][(j+1)%(2*K)]^=dp[e[i].to][j];}
}
inline void dfs2(int x,int fa)
{
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
	{
		memcpy(tmp,dp[e[i].to],sizeof(tmp));
		for(int j=0;j<2*K;j++) dp[e[i].to][(j+1)%(2*K)]^=dp[x][j]^tmp[(j+2*K-1)%(2*K)];
		dfs2(e[i].to,x);
	}
}
int main()
{
	read(n),read(K);for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	for(int i=1;i<=n;i++) read(a[i]);
	dfs1(1,0),dfs2(1,0);
	for(int i=1,rs=0;i<=n;i++,rs=0)
	{
		for(int j=K;j<K*2;j++) rs^=dp[i][j];
		printf("%d%c",!!rs,i==n?'\n':' ');
	}
	return 0;
}