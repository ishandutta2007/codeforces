#include <iostream>
using namespace std;
int dp[4005];
int main()
{
	int n,a,b,c;
	cin >> n >> a >> b >> c;
	for (int i=1;i<=n;i++)
	{
		if (a<=i && dp[i-a]!=-1)
		dp[i]=max(dp[i],1+dp[i-a]);
		if (b<=i && dp[i-b]!=-1)
		dp[i]=max(dp[i],1+dp[i-b]);
		if (c<=i && dp[i-c]!=-1)
		dp[i]=max(dp[i],1+dp[i-c]);
		if (!dp[i])
		dp[i]=-1;
	}
	cout << dp[n];
}