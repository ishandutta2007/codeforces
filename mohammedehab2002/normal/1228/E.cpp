#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int n,k,ncr[255][255],dp[255][255];
long long pw[2][255];
int solve(int a,int b)
{
	if (!a)
	return !b;
	if (dp[a][b]!=-1)
	return dp[a][b];
	int ans=0;
	for (int c=0;c<=b;c++)
	{
		long long add=pw[0][n-b];
		if (!c)
		add=(add-pw[1][n-b]+mod)%mod;
		add=(add*ncr[b][c])%mod;
		add=(add*pw[1][b-c])%mod;
		ans=(ans+add*solve(a-1,b-c))%mod;
	}
	return dp[a][b]=ans;
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=0;i<=n;i++)
	{
		ncr[i][0]=1;
		for (int j=1;j<=i;j++)
		ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%mod;
	}
	pw[0][0]=1;
	pw[1][0]=1;
	for (int i=0;i<2;i++)
	{
		for (int j=1;j<=n;j++)
		pw[i][j]=(pw[i][j-1]*(k-i))%mod;
	}
	memset(dp,-1,sizeof(dp));
	printf("%d",solve(n,n));
}