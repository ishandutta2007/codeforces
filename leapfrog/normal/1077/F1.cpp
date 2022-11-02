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
int n,K,m,a[205];ll dp[205][205];
int main()
{
	read(n),read(K),read(m);for(int i=1;i<=n;i++) read(a[i]);
	memset(dp,~0x3f,sizeof(dp)),dp[0][0]=0;
	for(int k=1;k<=m;k++) for(int i=1;i<=n;i++)
		for(int j=max(0,i-K);j<i;j++) dp[i][k]=max(dp[j][k-1]+a[i],dp[i][k]);
	//for(int i=1;i<=K;i++) for(int j=1;j<=n;j++) printf("%d%c",dp[j][i],j==n?'\n':' ');
	ll mx=-1;for(int i=n-K+1;i<=n;i++) mx=max(mx,dp[i][m]);
	return printf("%lld\n",mx<0?-1:mx),0;
}