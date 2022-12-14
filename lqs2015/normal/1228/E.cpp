#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,k,dp[333][333],pw1[333],pw2[333];
int c[333][333];
void add(int &x,int y)
{
	x+=y;
	if (x>=mod) x-=mod;
}
int main()
{
	cin>>n>>k;
	c[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		c[i][0]=1;
		for (int j=1;j<=i;j++)
		{
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
	pw1[0]=pw2[0]=1;
	for (int i=1;i<=n;i++)
	{
		pw1[i]=1ll*pw1[i-1]*k%mod;
		pw2[i]=1ll*pw2[i-1]*(k-1)%mod;
	}
	dp[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=n;j++)
		{
			for (int k=j;k<=n;k++)
			{
				add(dp[i][k],1ll*dp[i-1][j]*pw1[j]%mod*c[n-j][n-k]%mod*pw2[n-k]%mod);
				if (j==k) add(dp[i][k],-1ll*dp[i-1][j]*pw2[n]%mod+mod);
			}
		}
	}
	printf("%d\n",dp[n][n]);
	return 0;
}