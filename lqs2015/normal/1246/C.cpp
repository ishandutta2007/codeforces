#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int mod=1e9+7;
int n,m,dp[2222][2222][2],cf[2222][2222][2],suf[2222][2222][2],r,ans;
bool f[2222][2222];
char s[2222];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for (int j=1;j<=m;j++)
		{
			if (s[j-1]=='R') f[i][j]=1;
		}
	}
	for (int i=n;i>=1;i--)
	{
		for (int j=m;j>=1;j--)
		{
			suf[i][j][0]=suf[i+1][j][0]+f[i][j];
			suf[i][j][1]=suf[i][j+1][1]+f[i][j];
		}
	}
	dp[1][1][0]=dp[1][1][1]=1;
	if (n==1 && m==1)
	{
		if (f[1][1]) printf("0\n");
		else printf("1\n");
		return 0;
	}
	cf[1][1][0]=cf[1][1][1]=1;
	cf[2][1][0]=cf[1][2][1]=-1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			dp[i][j][0]=(dp[i-1][j][0]+cf[i][j][0])%mod;
			dp[i][j][1]=(dp[i][j-1][1]+cf[i][j][1])%mod;
			if (j<m) 
			{
				r=m-suf[i][j+1][1];
				if (j+1<=r)
				{
					cf[i][j+1][1]=(cf[i][j+1][1]+dp[i][j][0])%mod;
					cf[i][r+1][1]=(cf[i][r+1][1]-dp[i][j][0])%mod;
				}
			}
			if (i<n)
			{
				r=n-suf[i+1][j][0];
				if (i+1<=r)
				{
					cf[i+1][j][0]=(cf[i+1][j][0]+dp[i][j][1])%mod;
					cf[r+1][j][0]=(cf[r+1][j][0]-dp[i][j][1])%mod;
				}
			}
		}
	}
	ans=(dp[n][m][0]+dp[n][m][1])%mod;
	printf("%d\n",(ans+mod)%mod);
	return Accepted;
}