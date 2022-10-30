//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}int Ca;
int n,a[2005];ll dp[2005][2005];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);for(int l=1;l<n;l++) for(int i=1,j=i+l;j<=n;i++,j++)
		dp[i][j]=min(dp[i][j-1]+a[j-1]-a[i],dp[i+1][j]+a[j]-a[i+1]);
	printf("%lld\n",dp[1][n]+a[n]-a[1]);
}
int main() {return solve(),0;}