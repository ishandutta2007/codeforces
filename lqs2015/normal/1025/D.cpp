#include<iostream>
#include<cstdio>
using namespace std;
int n,a[777],dp[777][777][2],l,r,x;
int mp[777][777];
int gcd(int a,int b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=0;i<=n+1;i++)
	{
		for (int j=0;j<=n+1;j++)
		{
			if (!i || !j || i==n+1 || j==n+1) mp[i][j]=1;
			else if (gcd(a[i],a[j])>1) mp[i][j]=1;
		}
	}
	for (int i=1;i<=n+1;i++) 
	{
		if (mp[i+1][i]) dp[i][i][1]=1;
		if (mp[i-1][i]) dp[i][i][0]=1;
		dp[i][i-1][0]=dp[i][i-1][1]=1;
	}
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<=n-i+1;j++)
		{
			l=j;r=j+i-1;
			x=l-1;
			for (int k=l;k<=r;k++)
			{
				if (mp[x][k]) dp[l][r][0]|=(dp[l][k-1][1]&dp[k+1][r][0]);
			}
			x=r+1;
			for (int k=l;k<=r;k++)
			{
				if (mp[x][k]) dp[l][r][1]|=(dp[l][k-1][1]&dp[k+1][r][0]);
			}
		}
	}
	if (dp[1][n][0]) printf("Yes\n");
	else printf("No\n");
	return 0;
}