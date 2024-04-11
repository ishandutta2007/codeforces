#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int m, n, k , t;
	cin >> m >> n >> k >> t;
	vector <int> a(m);
	for(int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	vector <pair <int, pair <int, int> > > x(k);
	for(int i = 0; i < k; i++)
	{
		cin >> x[i].first >> x[i].second.first >> x[i].second.second;
	}
	sort(x.begin(), x.end());
	sort(a.begin(), a.end());
	int l = 0, r = m + 1;
	while(r - l > 1)
	{
		int midd = (r + l) / 2;
		int d = a[m - midd];
		vector <pair <int, int> > e;
		for(int i = 0; i < k; i++)
		{
			if(x[i].second.second > d)
			{
				e.push_back({x[i].first, x[i].second.first});
			}
		}
		int sum = 0;
		for(int i = 0; i < e.size(); i++){
			int R = e[i].second;
			int st = e[i].first;
			while(i < e.size() - 1 && e[i + 1].first <= R)
			{
				R = max(e[i + 1].second, R);
				i++;
			}
			sum += 2 * (R - st + 1);
		}
		sum += n + 1;
		if(sum <= t)
		{
			l = midd;
		}
		else
		{
			r = midd;
		}
	}
	cout << l;
	return 0;
}