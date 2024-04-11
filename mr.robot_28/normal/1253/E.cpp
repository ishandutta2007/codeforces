#include <bits/stdc++.h>
using namespace std;
vector <int> t;
void update(int v, int l, int r, int al, int ar, int up)
{
	if(l >= al && r <= ar)
	{
		t[v] = min(t[v], up);
	}
	else if(l <= ar && r >= al)
	{
		update(v * 2, l, (r + l) / 2, al, ar, up);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, up);
	}
}
int ans(int v, int l, int r, int ind)
{
	if(l == r)
	{
		return t[v];
	}
	else if(ind <= (r + l) / 2)
	{
		return min(t[v], ans(v * 2, l, (r + l) / 2, ind));
	}
	else 
	{
		return min(t[v], ans(v * 2 + 1, (r + l) / 2 + 1, r, ind));
	}
}
signed main()
{
	int n, m;
	cin >> n >> m;
	vector <int> dp(m, 1e9);
	t.resize(m * 4, 1e9);
	vector <pair <int, int> > a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
		a[i].first--;
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(a[j].first >= i)
			{
				if(i == 0)
				{
					if(a[j].first - a[j].second <= i)
					{
						update(1, 0, m - 1, 0, min(m - 1, a[j].first + a[j].second), 0);
					}
					else
					{
						int k = a[j].first - a[j].second - i;
						update(1, 0, m - 1, 0, min(m - 1, a[j].first + a[j].second + k), k);
					}
				}
				else
				{
					if(abs(a[j].first - i) <= a[j].second)
					{
						update(1, 0, m - 1, max(0, a[j].first - a[j].second), min(m - 1, a[j].first + a[j].second), dp[i - 1]);
					}
					else
					{
						int k = a[j].first - i - a[j].second;
						update(1, 0, m - 1, max(0, a[j].first - k - a[j].second), min(m - 1, a[j].first + k + a[j].second), dp[i - 1] + k);
					}
				}
			}
		}
		if(i != 0)
		{
			dp[i] = min(dp[i - 1] + 1, dp[i]);
		}
		dp[i] = min(dp[i], ans(1, 0, m - 1, i));
	}
	cout << dp[m - 1];
    return 0;
}