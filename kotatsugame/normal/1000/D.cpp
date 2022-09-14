#include<iostream>
using namespace std;
long long M=998244353;
long long ans;
int n,a[1000];
long long C[1010][1010];
long long dp[1010];
main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<=n;i++)C[i][0]=C[i][i]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%M;
		}
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		for(int j=1;j<i;j++)
		{
			dp[i]=(dp[i]+(i-j>=a[j-1]&&a[j-1]>0?C[i-j-1][a[j-1]-1]:0)*(1+dp[j-1])%M)%M;
		}
	}
	cout<<dp[n]<<endl;
}