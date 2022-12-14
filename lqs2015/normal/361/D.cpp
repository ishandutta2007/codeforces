#include<iostream>
#include<cmath>
using namespace std;
long long dp[2222],n,k,a[2222],l,r;
long long Abs(long long x)
{
	return max(x,-x);
}
bool check(long long num)
{
	dp[1]=0;
	for (long long i=2;i<=n;i++) dp[i]=i-1;
	long long mn=n-1;
	for (long long i=2;i<=n;i++)
	{
		for (long long j=1;j<i;j++)
		{
			if ((Abs(a[i]-a[j])+i-j-1)/(i-j)<=num)
			{
				dp[i]=min(dp[i],dp[j]+i-j-1);
			}
		}
		mn=min(mn,dp[i]+n-i);
	}
	return mn<=k;
}
int main()
{
	cin>>n>>k;
	for (long long i=1;i<=n;i++) cin>>a[i];
	l=0;r=2e9+1;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if (check(mid)) r=mid-1;
		else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}