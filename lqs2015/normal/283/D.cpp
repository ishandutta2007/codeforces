#include<iostream>
#include<cstdio>
using namespace std;
long long dp[5555],a[5555],y[5555],n,ts,ans;
bool ok(long long j,long long i)
{
	if (a[j]%a[i]) return 0;
	if (i-j==y[i]-y[j] || y[i]<i-j) return 1;
	return 0;
}
int main()
{
	cin>>n;
	for (long long i=1;i<=n;i++)
	{
		cin>>a[i];
		while(a[i]%2==0 && a[i]) 
		{
			y[i]++;
			a[i]/=2;
		}
	}
	dp[1]=0;
	for (long long i=2;i<=n;i++) dp[i]=i-1;
	for (long long i=2;i<=n;i++)
	{
		for (long long j=1;j<i;j++)
		{
			if (ok(j,i)) dp[i]=min(dp[i],dp[j]+i-j-1);
		}
	}
	ans=1e9;
	for (long long i=1;i<=n;i++)
	{
		ans=min(ans,dp[i]+n-i);
	}
	cout<<ans<<endl;
	return 0;
}