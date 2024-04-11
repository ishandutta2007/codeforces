//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,h;long long dp[55][55];
int main()
{
	read(n),read(h);for(int i=0;i<=n;i++) dp[i][0]=1;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int k=0;k<j;k++) dp[i][j]+=dp[i-1][k]*dp[i-1][j-k-1];
	return printf("%lld\n",dp[n][n]-dp[h-1][n]),0;
}