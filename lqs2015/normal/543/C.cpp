#include<iostream>
#include<cstdio>
using namespace std;
int a[22][22],n,m,sum[1100001],dp[22][1100001],k,p,ans[1100001],mask,cur[22][22];
bool f,flag;
string s[22];
int main()
{
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		cin>>a[i][j];
	}
	for (int i=0;i<m;i++)
	{
		sum[0]=0;k=1;p=0;
		for (int j=1;j<(1<<n);j++)
		{
			if (k*2<=j) 
			{
				k*=2;
				p++;
			}
			sum[j]=sum[j-k]+a[p][i];
		}
		k=1;p=0;
		dp[i][0]=0;
		for (int j=1;j<(1<<n);j++)
		{
			if (k*2<=j)
			{
				k*=2;
				p++;
			}
			dp[i][j]=min(dp[i][j-k]+a[p][i],sum[j-k]);
		}
	}
	for (int i=0;i<n;i++)
	{
		flag=0;
		for (int j=0;j<m;j++)
		{
			f=0;
			for (int k=0;k<n;k++)
			{
				if (i==k) continue;
				if (s[i][j]==s[k][j])
				{
					f=1;
					break;
				}
			}
			if (!f) 
			{
				flag=1;
				break;
			}
		}
		if (flag) mask|=(1<<i);
	}
	for (int i=0;i<(1<<n);i++) ans[i]=1e9;
	ans[mask]=0;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			for (int k=0;k<n;k++)
			{
				if (s[i][j]==s[k][j]) cur[i][j]|=(1<<k);
			}
		}
	}
	for (int i=0;i<(1<<n);i++)
	{
		if (ans[i]==1e9) continue;
		for (int j=0;j<n;j++)
		{
			if (i&(1<<j)) continue;
			for (int k=0;k<m;k++)
			{
				mask=cur[j][k];
				ans[i|mask]=min(ans[i|mask],ans[i]+dp[k][mask]);
				ans[i|(1<<j)]=min(ans[i|(1<<j)],ans[i]+a[j][k]);
			}
		}
	}
	cout<<ans[(1<<n)-1]<<endl;
	return 0;
}