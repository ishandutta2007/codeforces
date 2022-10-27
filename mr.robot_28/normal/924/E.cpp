#include <cstdio>
#include <algorithm>
#include<bits/stdc++.h>
#include <utility>
using namespace std;
int n, l, r;
int h = 0;
vector <pair <int, int> > a;
bool cmp(pair <int, int> a, pair <int, int> b)
{
	if(a.second != b.second)
	{
		return a.second < b.second;
	}
	return a.first > b.first;
}
signed main()
{
	cin >> n >> l >> r;
	a.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		h += a[i].first;
	}
	l = h - l;
	r = h - r;
	swap(l, r);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].second;
	}
	sort(a.begin(), a.end(), cmp);
	vector <int> dp(h + 1, -1e9);
	dp[0] = 0;
	int res = 0;
	for(int i = 0; i < n; i++)
	{
		for(int h1 = h - a[i].first; h1 >= 0; h1--)
		{
			if(a[i].second == 1 && h1 + a[i].first >= l && h1 + a[i].first <= r)
			{
				dp[h1 + a[i].first] = max(dp[h1 + a[i].first], dp[h1] + 1);
			}
			else
			{
				dp[h1 + a[i].first] = max(dp[h1 + a[i].first], dp[h1]);
			}
		}
	}
	for(int i = 0; i <= h; i++)
	{
		res= max(res, dp[i]);
	}
	cout << res;
    return 0;
}