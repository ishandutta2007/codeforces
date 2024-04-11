#include<bits/stdc++.h>
 
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	vector <int> dp(5, 1e18);
	dp[0] = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == 'h')
		{
			dp[1] = min(dp[1], dp[0]);
			dp[0] += A[i];
		}
		else if(s[i] == 'a')
		{
			dp[2] = min(dp[2], dp[1]);
			dp[1] += A[i];
		}
		else if(s[i] == 'r')
		{
			dp[3] = min(dp[3], dp[2]);
			dp[2] += A[i];
		}
		else if(s[i] == 'd')
		{
			dp[3] += A[i];
		}
	}
	int ans = 1e18;
	for(int i = 0; i < 4; i++)
	{
		ans = min(ans, dp[i]);
	}
	cout << ans;
	return 0;
}