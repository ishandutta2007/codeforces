#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007
vector<int> fact[2005];
int dp[2005][2005];
int main()
{
	for (int i=1;i<=2000;i++)
	{
		for (int x=1;x<=i;x++)
		{
			if (i%x==0)
			fact[i].push_back(x);
		}
	}
	int n,k;
	cin >> n >> k;
	for (int i=1;i<=n;i++)
	dp[1][i]=1;
	for (int i=2;i<=k;i++)
	{
		for (int x=1;x<=n;x++)
		{
			for (int j=0;j<fact[x].size();j++)
			dp[i][x]=(dp[i][x]+dp[i-1][x/fact[x][j]])%mod;
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	ans=(ans+dp[k][i])%mod;
	cout << ans;
}