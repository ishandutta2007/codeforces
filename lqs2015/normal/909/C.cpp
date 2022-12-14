#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,arr[5555],cnt,dp[5555][5555],cur,ans;
bool f[5555];
char opt[11];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",opt);
		if (opt[0]=='f') f[i]=1;
	}
	for (int i=1;i<=n;i++)
	{
		if (!f[i]) 
		{
			if (cur) arr[++cnt]=cur;
			else arr[++cnt]=12138;
			cur=0;
		}
		else cur++;
	}
	if (cur) arr[++cnt]=cur;
	dp[0][0]=1;
	for (int i=0;i<cnt;i++)
	{
		for (int j=0;j<=n;j++)
		{
			if (!dp[i][j]) continue;
			if (arr[i+1]==12138)
			{
				dp[i+1][0]=(dp[i+1][0]+dp[i][j])%mod;
				dp[i+1][j+1]=(dp[i+1][j+1]-dp[i][j])%mod;
			}
			else
			{
				dp[i+1][arr[i+1]]=(dp[i+1][arr[i+1]]+dp[i][j])%mod;
				dp[i+1][arr[i+1]+j+1]=(dp[i+1][arr[i+1]+j+1]-dp[i][j])%mod;
			}
		}
		for (int j=1;j<=n;j++) dp[i+1][j]=(dp[i+1][j]+dp[i+1][j-1])%mod;
	}
	for (int j=0;j<=n;j++) ans=(ans+dp[cnt][j])%mod;
	printf("%d\n",(ans+mod)%mod);
	return 0;
}