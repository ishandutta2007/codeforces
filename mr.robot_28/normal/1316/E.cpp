#include<bits/stdc++.h>
using namespace std;

#define int long long
int cnt(int a)
{
	int ans = 0;
	while(a > 0)
	{
		if(a % 2 == 1)
		{
			ans++;
		}
		a = a / 2;
	}
	return ans;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, p, k;
	cin >> n >> p >> k;
	vector <pair <int, int> > A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i].first;
		A[i].second = i;
	}
	sort(A.begin(), A.end());
	reverse(A.begin(), A.end());
	vector <vector <int> > s(n, vector <int> (p));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < p; j++)
		{
			cin >> s[i][j];
		}
	}
	swap(k, p);
	vector <int> dp((1 << k), 0);
	vector <int> dp1((1 << k), 0);
	vector <bool> can((1 << k));
	can[0] = true;
	for(int i = 0; i < n; i++)
	{
		int j = A[i].second;
		int a = A[i].first;
		for(int mask = (1 << k) - 1; mask  >= 0; mask--)
		{
			if(!can[mask])
			{
				continue;
			}
			int p1 = cnt(mask);
			if(i - p1 >= p)
			{
				dp1[mask] = max(dp1[mask], dp[mask]);
			}
			else
			{
				dp1[mask] = max(dp1[mask], dp[mask] + a);
			}
			for(int t = 0; t < k; t++)
			{
				if(((1 << t) & mask) == 0)
				{
					can[mask | (1 << t)] = true;
					dp1[mask | (1 << t)] = max(dp1[mask | (1 << t)], dp[mask] + s[j][t]);
				}
			}
		}
		for(int j = 0; j < (1 << k); j++)
		{
			dp[j] = dp1[j];
			dp1[j] = 0;
		}
	}
	cout << dp[(1 << k) - 1];
	return 0;
}