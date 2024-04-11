#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
const int mod=1e9+7;
int dp[5005],sum[5005][5005],n,k,f[5005][5005];
string s;
bool can(int i,int j,int k)
{
	if (f[k-1][j-1]>i-j+1) return 0;
	return s[k+f[k-1][j-1]-2]<s[j+f[k-1][j-1]-2];
}
int main()
{
	cin>>n>>s;
	sum[0][0]=1;
	for (int i=n-1;i>=0;i--)
	{
		for (int j=n-1;j>=i;j--)
		{
			if (s[i]!=s[j]) f[i][j]=1;
			else f[i][j]=f[i+1][j+1]+1;
		}
	}
	for (int i=1;i<=n;i++)
	{
		memset(dp,0,sizeof(dp));
		for (int j=1;j<=i;j++)
		{
			if (s[j-1]=='0') continue;
			k=2*j-i-1;
			if (k<=0)
			{
				dp[j]=sum[j-1][j-1];
			}
			else
			{
				dp[j]=(sum[j-1][j-1]-sum[j-1][k]+mod)%mod;
				if (can(i,j,k)) dp[j]=((dp[j]+sum[j-1][k])%mod-sum[j-1][k-1]+mod)%mod;
			}
		}
		sum[i][0]=0;
		for (int j=1;j<=i;j++)
		{
			sum[i][j]=(sum[i][j-1]+dp[j])%mod;
		}
	}
	printf("%d\n",sum[n][n]);
	return 0;
}