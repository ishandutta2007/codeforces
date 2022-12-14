#include<iostream>
#include<cstring>
using namespace std;
long long n,k,a[55],msk,cur;
bool dp[55][55];
bool can(long long msk)
{
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for (long long i=1;i<=k;i++)
	{
		for (long long j=1;j<=n;j++)
		{
			cur=a[j];
			for (long long p=j-1;p>=0;p--)
			{
				if ((cur&msk)==msk && dp[i-1][p]) dp[i][j]=1;
				cur+=a[p];
			}
		}
	}
	return dp[k][n];
}
int main()
{
	cin>>n>>k;
	for (long long i=1;i<=n;i++) cin>>a[i];
	for (long long i=60;i>=0;i--)
	{
		if (can(msk|(1ll<<i))) msk|=(1ll<<i);
	}
	cout<<msk<<endl;
	return 0;
}