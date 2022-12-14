#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,K,cnt;
int a[555];
bool dp[555][555],ddp[555][555];
int main()
{
	scanf("%d%d",&n,&K);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	ddp[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		memset(dp,0,sizeof(dp));
		for (int j=0;j<=500;j++)
		{
			for (int k=0;k<=500;k++)
			{
				if (!ddp[j][k]) continue;
				dp[j][k]=1;
				if (j+a[i]<=500)
				{
					dp[j+a[i]][k]=1;
					dp[j+a[i]][k+a[i]]=1;
				}
			}
		}
		for (int j=0;j<=500;j++)
		{
			for (int k=0;k<=500;k++)
			{
				ddp[j][k]=dp[j][k];
			}
		}
	}
	for (int i=0;i<=K;i++)
	{
		if (dp[K][i]) cnt++;
	}
	cout<<cnt<<endl;
	for (int i=0;i<=K;i++)
	{
		if (dp[K][i]) cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}