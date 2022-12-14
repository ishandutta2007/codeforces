#include<bits/stdc++.h>
using namespace std;
int n,m,dp[5555][5555],ans;
char s[5555],t[5555];
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s%s",s,t);
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			if (s[i]==t[j]) dp[i][j]=2;
		}
	}
	for (int i=0;i<n-1;i++)
	{
		for (int j=0;j<m-1;j++)
		{
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]-1);
			dp[i][j+1]=max(dp[i][j+1],dp[i][j]-1);
			if (s[i+1]==t[j+1]) dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+2);
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++) 
		ans=max(ans,dp[i][j]);
	}
	printf("%d\n",ans);
	return 0;
}