#include <bits/stdc++.h>
using namespace std;
vector <int> t;
vector <int> dp;
void build(int v, int l, int r)
{
	if(l == r)
	{
		t[v] = dp[l];
	}
	else
	{
		build(v * 2 ,l, (r + l) / 2);
		build(v * 2 + 1, (r + l) / 2 + 1, r);
		t[v] = min(t[v * 2], t[v * 2 + 1]);
	}
}
int ans(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return t[v];
	}
	else if(l <= ar && r >= al)
	{
		return min(ans(v * 2, l, (r + l) / 2, al, ar), ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
	}
	else
	{
		return 1e9;
	}
}
signed main()
{
	int k1, k2, k3;
	cin >> k1 >> k2 >> k3;
	int n = k1 + k2 + k3;
	vector <int> a(k1), b(k2), c(k3);
	for(int i = 0; i < k1; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < k2; i++)
	{
		cin >> b[i];
	}
	for(int i = 0; i < k3; i++)
	{
		cin >> c[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	swap(b, c);
	dp.resize(a.size() + 1);
	int j = 0;
	for(int i = 0; i <= a.size(); i++)
	{
		if(i == 0)
		{
			dp[i] = a.size();
		}
		else
		{
			int l = -1, r = c.size();
			while( r- l > 1)
			{
				int midd = (r + l) / 2;
				if(c[midd] > a[i - 1])
				{
					r = midd;
				}
				else
				{
					l = midd;
				}
			}
			dp[i] = r + a.size() - i;
		}
	}
	t.resize(4 * (a.size() + 1));
	build(1, 0, a.size());
	int anss = 1e9;
	for(int i = b.size(); i >= 0; i--)
	{
		if(i == b.size())
		{
			anss = min(anss, ans(1, 0, a.size(), 0, a.size()) + int(b.size()));
		}
		else
		{
			int sum = i; 
			int l = -1, r = a.size();
			while(r - l > 1)
			{
				int midd = (r + l) / 2;
				if(a[midd] < b[i])
				{
					l = midd;
				}
				else
				{
					r = midd;
				}
			}
			sum += ans(1, 0, a.size(), 0, l + 1);
			l = -1, r = c.size();
			while( r- l > 1)
			{
				int midd = (r + l) / 2;
				if(c[midd] > b[i])
				{
					r = midd;
				}
				else
				{
					l = midd;
				}
			}
			sum += c.size() - r;
			anss = min(anss, sum);
		}
	}
	cout << anss;
    return 0;
}