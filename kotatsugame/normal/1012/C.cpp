#include<iostream>
#include<algorithm>
#include<cstdio>
#include<utility>
using namespace std;
pair<int,int>dp[2505][5001];
int a[5000];
int n;
int func(int a,int b)
{
	return a<=b?b-a+1:0;
}
int memo[2555];
main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
	else if(n==2)
	{
		printf("%d\n",a[0]==a[1]);
		return 0;
	}
	for(int i=0;i<n;i++)dp[0][i].second=a[i];
	for(int i=1;i<=(n+1)/2;i++)memo[i]=1e9;
	dp[1][1].first=func(a[0],a[1]);
	dp[1][1].second=a[1]>=a[0]?a[0]-1:a[1];
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=(i-2)/2;j++)memo[j]=min(memo[j],dp[j][i-3].first);
		for(int j=1;j<=(i+1)/2;j++)
		{
			int ans=func(a[i-1],dp[j-1][i-2].second)+dp[j-1][i-2].first;
			ans=min(ans,func(a[i-1],a[i-2])+memo[j-1]);
			dp[j][i].first=ans+(i<n?func(a[i-1],a[i]):0);
			if(i<n)dp[j][i].second=a[i]>=a[i-1]?a[i-1]-1:a[i];
		}
		for(int j=1;j<=i/2;j++)
		{
			if(dp[j][i].first>dp[j][i-1].first)
			{
				dp[j][i].first=dp[j][i-1].first;
				if(i<n)dp[j][i].second=a[i];
			}
		}
	}
	for(int i=1;i<=(n+1)/2;i++)
	{
		printf("%d%c",dp[i][n].first,i==(n+1)/2?'\n':' ');
	}
}