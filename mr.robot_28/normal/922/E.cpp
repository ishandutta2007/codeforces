#include<iostream>
#include<vector>
using namespace std;
#define int long long
const int allcnt = 1e4;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, w, b, x;
	cin >> n >> w >> b >> x;
	vector <int> c(n);
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	vector <int> cost(n);
	for(int i = 0; i < n; i++)
	{
		cin >> cost[i];
	}
	vector <int> dp(allcnt + 1, -1e15), dp1(allcnt + 1, -1e15);
	vector <bool> can(allcnt + 1);
	can[0] = true;
	dp[0] = w;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= allcnt; j++)
		{
			dp1[j] = -1e15;
			if(can[j])
			{
				dp1[j] = min(dp[j] + x, w + b * j);
			}
		}
		for(int j = allcnt; j >= 0; j--)
		{
			for(int p = 1; p <= c[i]; p++)
			{
				if(p + j <= allcnt && can[j] && dp[j] -  cost[i] * p >= 0)
				{
					can[j + p] = true;
					dp1[j + p] = min(w + b * (p + j), max(dp[j] - cost[i] * p + x, dp1[j + p]));
				}
			}
		}
		for(int j = 0; j <= allcnt; j++)
		{
			dp[j] = dp1[j];
		}
	}
	int cnt = 0;
	for(int i = 0; i <= allcnt; i++)
	{
		if(can[i])
		{
			cnt = i;
		}
	}
	cout << cnt;
	return 0;
}