//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
const int P=1e9+7;int n,m,a[205],dp[205][205][1005];
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1),dp[0][0][0]=1;
	for(int i=0;i<n;i++) for(int j=0;j<=n;j++)
	{
		int x=(a[i+1]-a[i])*j;for(int k=0;k<=m-x;k++)
		{
			dp[i+1][j][k+x]=(dp[i+1][j][k+x]+1ll*dp[i][j][k]*(j+1))%P;
			if(j^n) dp[i+1][j+1][k+x]=(dp[i+1][j+1][k+x]+dp[i][j][k])%P;
			if(j) dp[i+1][j-1][k+x]=(dp[i+1][j-1][k+x]+1ll*dp[i][j][k]*j)%P;
		}
	}
	int res=0;for(int i=0;i<=m;i++) res=(res+dp[n][0][i])%P;
	return printf("%d\n",res),0;
}