#include <bits/stdc++.h>

using namespace std;
vector <pair <int, int> > mass;
vector <int> pref;
int n, k, s, t;
vector <int> a;
bool check(int ind)
{
	int val = mass[ind].second;
	int v = pref[ind];
	int minsum = 0;
	for(int i = 0; i < k - 1; i++)
	{
		int s1 = a[i + 1] - a[i];
		if(s1 > v)
		{
			return 0;
		}
		int x = 2 * s1 - v;
		x = max(x, 0);
		minsum += 2 * x;
		minsum += s1 - x;
	}
	int s1 = a[0];
	if(s1 > v)
	{
		return 0;
	}
	int x = 2 * s1 - v;
	x = max(x, 0);
	minsum += 2 * x;
	minsum += s1 - x;
	s1 = s - a[k - 1];
	if(s1 > v)
	{
		return 0;
	}
	x = 2 * s1 - v;
	x = max(x, 0);
	minsum += 2 * x;
	minsum += s1 - x;
	if(minsum <= t)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k >> s >> t;
	mass.resize(n);
	pref.resize(n);
	a.resize(k);
	for(int i = 0; i < n; i++)
	{
		cin >> mass[i].first >> mass[i].second;
	}
	for(int i = 0; i < k; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	sort(mass.begin(), mass.end());
	for(int i = 0; i < n; i++)
	{
		pref[i] = mass[i].second;
		if(i != 0)
		{
			pref[i] = max(pref[i - 1], pref[i]);
		}
	}
	int l = -1, r = n;
	while(r - l > 1)
	{
		int midd = (r + l) / 2;
		if(check(midd))
		{
			r = midd;
		}
		else
		{
			l = midd;
		}
	}
	if(r == n)
	{
		cout << -1;
	}
	else
	{
		cout << mass[r].first;
	}
	return 0;
}