#include<bits/stdc++.h>
using namespace std;
#define int long long
int min(int a, int b)
{
	if(a < b)
	{
		return a;
	}
	return b;
}
int max(int a, int b)
{
	if(a > b)
	{
		return a;
	}
	return b;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <vector <int> > dp(n + 1, vector <int> (31, 1e9));
	dp[0][0] = 0;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		for(int j = 0; j <= 30; j++)
		{
			dp[i + 1][min(30, j + a / 1000)] = min(dp[i + 1][min(30, j + a / 1000)], dp[i][j] + a);
		}
		for(int j = 0; j <= 30; j++)
		{
			dp[i + 1][max(0, j - a / 100)] = min(dp[i + 1][max(0, j - a/ 100)], dp[i][j] + a - min(j, a/ 100) * 100);
		}
	}
	int ans = 1e9;
	for(int i = 0; i <= 30; i++)
	{
		ans = min(ans, dp[n][i]);
	}
	cout << ans;
	return 0;
}