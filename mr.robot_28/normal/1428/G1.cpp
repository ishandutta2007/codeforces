#include<bits/stdc++.h>
using namespace std;
#define int long long
long long max(long long a, long long b)
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
	int k;
	cin >> k;
	vector <int> f(6);
	for(int i = 0; i < 6; i++)
	{
		cin >> f[i];
	}
	int q;
	cin >> q;
	int n;
	cin >> n;
	vector <long long> dp(n + 1, -1e18);
	dp[0] = 0;
	for(int i = 0; i <= 5; i++)
	{
		long long s = 3 * (k - 1);
		long long g = 1;
		while(s > 0)
		{
			g = min(g, s);
			long long val = g * f[i];
			long long w = g * pow(10, i) * 3;
			for(int j = n; j >= w; j--)
			{
				dp[j] = max(dp[j], dp[j - w] + val);
			}
			s -= g;
			g *= 2;
		}
	}
	long long ans = 0;
	for(int i = 0; i <= n; i++)
	{
		long long sum = 0;
		int x = i;
		for(int d = 0; d <= 5; d++)
		{
			int ost = x % 10;
			if(ost % 3 == 0)
			{
				sum += 1LL * (ost / 3) * f[d];
			}
			x /= 10;
		}
		ans = max(ans, sum + dp[n - i]);
	}
	cout << ans;
	return 0;
}