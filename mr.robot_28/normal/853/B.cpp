#include<bits/stdc++.h>
using namespace std;
#define int long long
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
	int n, m, k;
	cin >> n >> m >> k;
	vector <pair <pair <int, int>, int> > mass1, mass2;
	for(int i = 0; i < m; i++)
	{
		int d, f, t, c;
		cin >> d >> f >> t >> c;
		if(f == 0)
		{
			mass2.push_back({{d, t}, c});
		}
		else
		{
			mass1.push_back({{d, f}, c});
		}
	}
	sort(mass1.begin(), mass1.end());
	sort(mass2.begin(), mass2.end());
	if(mass1.size() < n || mass2.size() < n)
	{
		cout << -1;
		return 0;
	}
	vector <int> ans1(mass1.size()), can1(mass1.size(), false);
	vector <int> ans2(mass2.size()), can2(mass2.size(), false);
	vector <int> dp(n + 1, -1);
	int cnt = 0;
	int sum1 = 0;
	for(int i = 0; i < mass1.size(); i++)
	{
		int ind = mass1[i].first.second;
		int c = mass1[i].second;
		if(dp[ind] == -1)
		{
			sum1 += c;
			cnt++;
			dp[ind] = c;
		}
		else
		{
			sum1 -= dp[ind];
			dp[ind] = min(dp[ind], c);
			sum1 += dp[ind];
		}
		if(cnt == n)
		{
			can1[i] = true;
			ans1[i] = sum1;
		}
		else
		{
			can1[i] = false;
		}
	}
	cnt = 0, sum1 = 0;
	for(int i = 0; i <= n; i++)
	{
		dp[i] =- 1;
	}
	for(int i = mass2.size() - 1; i >= 0; i--)
	{
		int ind = mass2[i].first.second;
		int c = mass2[i].second;
		if(dp[ind] == -1)
		{
			sum1 += c;
			cnt++;
			dp[ind] = c;
		}
		else
		{
			sum1 -= dp[ind];
			dp[ind] = min(dp[ind], c);
			sum1 += dp[ind];
		}
		if(cnt == n)
		{
			can2[i] = true;
			ans2[i] = sum1;
		}
		else
		{
			can2[i] = false;
		}
	}
	int ans = 1e18;
	for(int i = 0; i < mass1.size(); i++)
	{
		if(!can1[i])
		{
			continue;
		}
		int l = -1, r = mass2.size();
		while(r - l > 1)
		{
			int midd = (r + l) / 2;
			if(mass2[midd].first.first < mass1[i].first.first + k + 1)
			{
				l = midd;
			}
			else
			{
				r = midd;
			}
		}
		if(r == mass2.size() || !can2[r])
		{
			continue;
		}
		ans = min(ans, ans1[i] + ans2[r]);
	}
	if(ans == 1e18)
	{
		cout << -1;
		return 0;
	}
	cout << ans;
	return 0;
}