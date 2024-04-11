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
int Ca,n,a[100005];ll K,dp[100005];const ll INF=1e18+5;
inline void solve()
{
	read(n),read(K);for(int i=0;i<=n;i++) dp[i]=0;
	dp[n+1]=1;int wh;char fg=0;for(int i=n;i;i--)
	{
		for(int j=i+1;j<=n+1;j++) dp[i]=min(dp[j]+dp[i],INF);
		if(dp[i]>=K) {wh=i-1;break;}else if(i==1) fg=1;
	}
	if(fg) return puts("-1"),void();
	for(int i=1;i<=wh;i++) a[i]=i;
	while(wh<n) for(int i=wh+2;i<=n+1;i++)
	{
		K-=dp[i];if(K<=0)
		{
			K+=dp[i],a[wh+1]=i-1;
			for(int j=wh+2;j<i;j++) a[j]=a[j-1]-1;
			wh=i-1;break;
		}
	}
	for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
}
int main() {for(read(Ca);Ca--;) solve();return 0;}