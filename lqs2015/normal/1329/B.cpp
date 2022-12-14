#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,test,d,m,arr[33],dp[55][55],ans;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&d,&m);
		for (int i=0;i<=29;i++)
		{
			arr[i]=max(0,min(d,(1<<(i+1))-1)-(1<<i)+1);
		}
		memset(dp,0,sizeof(dp));
		for (int i=0;i<=29;i++) dp[1][i]=arr[i];
		for (int i=1;i<30;i++)
		{
			for (int j=0;j<=29;j++)
			{
				if (!dp[i][j]) continue;
				for (int k=j+1;k<=29;k++)
				{
					dp[i+1][k]=(1ll*dp[i][j]*arr[k]+dp[i+1][k])%m;
				}
			}
		}
		ans=0;
		for (int i=1;i<=30;i++)
		{
			for (int j=0;j<=29;j++)
			{
				ans=(ans+dp[i][j])%m;
			}
		}
		printf("%d\n",ans);
	}
	return Accepted;
}