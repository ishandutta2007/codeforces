#include<bits/stdc++.h>
using namespace std;
int l,r,n,dp[555][555];
char s[555];
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=0;i<n;i++)
	{
		for (int j=0;i+j<n;j++)
		{
			l=j;r=i+j;
			dp[l][r]=dp[l+1][r]+1;
			for (int k=l+1;k<=r;k++)
			{
				if (s[l]==s[k]) dp[l][r]=min(dp[l][r],dp[l+1][k-1]+dp[k][r]);
			}
		}
	}
	printf("%d\n",dp[0][n-1]);
	return 0;
}