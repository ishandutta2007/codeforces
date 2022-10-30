//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int n,a[2][100005];ll dp[2][100005];
int main()
{
	read(n);for(int k=0;k<2;k++) for(int i=1;i<=n;i++) read(a[k][i]);
	for(int i=1;i<=n;i++)
	{
		dp[0][i]=max(dp[0][i-1],dp[1][i-1]+a[0][i]);
		dp[1][i]=max(dp[1][i-1],dp[0][i-1]+a[1][i]);
	}
	return printf("%lld\n",max(dp[0][n],dp[1][n])),0;
}