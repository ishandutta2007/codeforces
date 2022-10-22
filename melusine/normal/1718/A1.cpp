#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int dp[5005][8193];
int a[5005];
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<8192;j++)
			{
				dp[i][j]=1000000000;
			}
		}
		dp[0][0]=0;
		int minn;
		for(int i=1;i<=n;i++)
		{
			minn=dp[i-1][0];
			for(int j=1;j<8192;j++)minn=min(minn,dp[i-1][j]+1);
			dp[i][a[i]]=minn;
			for(int j=0;j<8192;j++)dp[i][j]=min(dp[i][j],dp[i-1][j^a[i]]+1);
		}
		minn=dp[n][0];
		for(int i=1;i<8192;i++)minn=min(minn,dp[n][i]+1);
		printf("%d\n",minn);
	}
}