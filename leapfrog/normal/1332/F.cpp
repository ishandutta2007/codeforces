//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
const int P=998244353;int n,dp[300005][2][2];
struct edge{int to,nxt;}e[600005];int et,head[300005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x,int fa)
{
	dp[x][1][1]=dp[x][1][0]=1;int del=1;
	for(int i=head[x],y=e[i].to;i;y=e[i=e[i].nxt].to) if(y^fa)
	{
		dfs(y,x),del=1ll*del*(dp[y][0][0]+dp[y][0][1])%P;
		dp[x][1][1]=(0ll+dp[y][1][0]+dp[y][0][0]+dp[y][0][1])*dp[x][1][1]%P;
		dp[x][1][0]=(0ll+dp[y][1][0]+dp[y][0][0]+dp[y][0][1]+dp[y][1][1])*dp[x][1][0]%P;
	}
	dp[x][0][1]=(dp[x][1][1]-del+P)%P,dp[x][0][0]=dp[x][1][0];
//	printf("%d : %d , %d , %d , %d\n",x,dp[x][0][0],dp[x][0][1],dp[x][1][0],dp[x][1][1]);
}
int main()
{
	read(n);for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	return dfs(1,0),printf("%d\n",(dp[1][0][0]+dp[1][0][1]-1)%P),0;
}