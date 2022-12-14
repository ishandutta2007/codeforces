#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long dp[222][5666],mx[222][5666];
long long n,k,two[222],fiv[222],x,mxs,ans;
int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		while(x)
		{
			if (x&1) break;
			two[i]++;
			x/=2;
		}
		while(x)
		{
			if (x%5) break;
			fiv[i]++;
			x/=5;
		}
		mxs+=fiv[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=mxs;j++)
		dp[i][j]=-1e9;
	}
	for (int i=1;i<=k;i++)
	{
		for (int j=0;j<=n;j++)
		{
			for (int k=0;k<=mxs;k++)
			mx[j][k]=-1e9;
		}
		mx[0][0]=0;
		for (int j=0;j<=mxs;j++)
		{
			for (int h=1;h<=n;h++)
			{
				mx[h][j]=max(mx[h-1][j],dp[h][j]);
			}
		}
		for (int j=1;j<=n;j++)
		{
			for (int k=0;k<=mxs;k++)
			dp[j][k]=-1e9;
		}
		for (int j=1;j<=n;j++)
		{
			for (int h=fiv[j];h<=mxs;h++)
			{
				dp[j][h]=mx[j-1][h-fiv[j]]+two[j];
			}
		}
	}
	for (long long i=0;i<=mxs;i++)
	{
		for (int j=1;j<=n;j++)
		{
			ans=max(ans,min(i,dp[j][i]));
		}
	}
	cout<<ans<<endl;
	return 0;
}