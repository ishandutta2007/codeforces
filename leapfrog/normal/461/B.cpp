//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,nxt;}e[100005];int et,head[100005];
const int P=1e9+7;int n,a[100005],dp[100005][2];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline int ksm(int x,int q=P-2) {int r=1;x%=P;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void solve(int x)
{
	if(a[x]) dp[x][0]=0,dp[x][1]=1;else dp[x][0]=1,dp[x][1]=0;
	for(int i=head[x];i;i=e[i].nxt) solve(e[i].to);
	for(int i=head[x];i;i=e[i].nxt) if(!a[x]) dp[x][0]=1ll*dp[x][0]*(dp[e[i].to][0]+dp[e[i].to][1])%P;
	for(int i=head[x];i;i=e[i].nxt) if(a[x]) dp[x][1]=1ll*dp[x][1]*(dp[e[i].to][1]+dp[e[i].to][0])%P;
		else dp[x][1]=(dp[x][1]+1ll*dp[x][0]*dp[e[i].to][1]%P*ksm(dp[e[i].to][0]+dp[e[i].to][1]))%P;
}
int main()
{
	read(n);for(int i=2,f;i<=n;i++) read(f),adde(f+1,i);
	for(int i=1;i<=n;i++) read(a[i]);
	return solve(1),printf("%d\n",dp[1][1]),0;
}