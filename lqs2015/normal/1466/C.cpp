#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int test,n,dp[111111][2][2],ans;
char s[111111];
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%s",s);
		n=strlen(s);
		for (int i=0;i<=n+1;i++) 
		{
			for (int j=0;j<2;j++)
			{
				for (int k=0;k<2;k++)
				dp[i][j][k]=1e9;
			}
		}
		dp[0][1][1]=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<2;j++)
			{
				for (int k=0;k<2;k++)
				{
					if ((k || i==1 || s[i-1]!=s[i-2]) && (j || i<=2 || s[i-1]!=s[i-3])) 
					{
						dp[i][k][0]=min(dp[i][k][0],dp[i-1][j][k]);
					}
					dp[i][k][1]=min(dp[i][k][1],dp[i-1][j][k]+1);
				}
			}
		}
		ans=1e9;
		for (int i=0;i<2;i++)
		{
			for (int j=0;j<2;j++)
			ans=min(ans,dp[n][i][j]);
		}
		printf("%d\n",ans);
	}
	return Accepted;
}