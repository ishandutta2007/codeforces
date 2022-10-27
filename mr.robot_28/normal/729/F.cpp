#include <bits/stdc++.h>

using namespace std;
int n;
vector <int> a;
vector <long long> pref;
unordered_map <int, long long> dp;
int maxk = 100;
inline long long rec(int l, int r, int k, int flag)
{
	if((r - l + 1) / k == 0)
	{
		return 0;
	}
	if((r - l + 1) == k)
	{
		if(flag)
		{
		return pref[r + 1] - pref[l]; 
		}
		return pref[l] - pref[r + 1];
	}
	int key = l * (n + 1) *  2 * maxk + r * 2 * maxk + 2 * k + flag;
	if(dp.count(key))
	{
		return dp[key];
	}
	if(flag)
	{
		dp[key] = max(pref[l + k] - pref[l] + rec(l + k, r, k, !flag),
		pref[l + k + 1] - pref[l] + rec(l + k + 1, r, k + 1, !flag));
	}
	else
	{
		dp[key] = min(-(pref[r + 1] - pref[r - k + 1]) + rec(l, r - k, k, !flag),
		-(pref[r + 1] - pref[r - k]) + rec(l, r - k - 1, k + 1, !flag));
	}
	return dp[key];
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	pref.resize(n + 1);
	a.resize(n);
	dp.rehash(6.2e7);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		pref[i + 1] = pref[i] + a[i];
	}
	cout << rec(0, n - 1, 1, true);
	return 0;
}