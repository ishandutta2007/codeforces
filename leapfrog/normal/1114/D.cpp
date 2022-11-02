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
int n,a[5005],dp[5005][5005][2];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	memset(dp,0x3f,sizeof(dp));for(int i=1;i<=n;i++) dp[i][i][0]=dp[i][i][1]=0;
	for(int j=1;j<=n;j++) for(int i=j;i>=1;i--) for(int k=0,c=a[i];k<2;k++,c=a[j])
	{
		if(i>1) dp[i-1][j][0]=min(dp[i-1][j][0],dp[i][j][k]+(c!=a[i-1]));
		if(j<n) dp[i][j+1][1]=min(dp[i][j+1][1],dp[i][j][k]+(c!=a[j+1]));
	}
	return printf("%d\n",min(dp[1][n][0],dp[1][n][1])),0;
}