#include<iostream>
#include<cstring>
using namespace std;
long long dp[55][2222],ans[55],k;
int main()
{
	for (int n=1;n<=30;n++)
	{
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n*50;j++)
			{
				dp[i][j]|=dp[i-1][j-1];
				if (j>=5) dp[i][j]|=dp[i-1][j-5];
				if (j>=10) dp[i][j]|=dp[i-1][j-10];
				if (j>=50) dp[i][j]|=dp[i-1][j-50];
			}
		}
		ans[n]=0;
		for (int i=1;i<=n*50;i++)
		{
			if (dp[n][i]) ans[n]++;
		}
	}
	scanf("%I64d",&k);
	if (k<=30) printf("%I64d\n",ans[k]);
	else printf("%I64d\n",ans[30]+(k-30)*49);
	return 0;
}