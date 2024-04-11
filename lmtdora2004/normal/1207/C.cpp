#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[200005][3];
string s;

signed main()
{
	int tests;
	cin>>tests;
	for(int test=1; test<=tests; test++)
	{
		int n, a, b;
		cin>>n>>a>>b;
		cin>>s;
		s='!'+s;
		dp[0][1]=b;
		dp[0][2]=1000000000000000;
		for(int i=1; i<=n; i++)
		{
			if(s[i]=='0')
			{
				dp[i][1]=min(dp[i-1][1]+a+b, dp[i-1][2]+2*a+b);
				dp[i][2]=min(dp[i-1][1]+2*a+2*b, dp[i-1][2]+a+2*b);
			}
			else
			{
				dp[i][1]=1000000000000000;
				dp[i][2]=dp[i-1][2]+a+2*b;
			}
		}
		cout<<min(dp[n][1], dp[n][2]+1000000000000000)<<endl;
	}
}