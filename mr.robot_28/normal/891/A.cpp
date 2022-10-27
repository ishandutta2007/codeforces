#include <bits/stdc++.h>
using namespace std;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> a(n);
	int e = 0;
	bool flag = false;
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		e = __gcd(e, a[i]);
		if(a[i] != 1)
		{
			cnt++;
		}
		else
		{
			flag = true;
		}
	}
	if(flag)
	{
		cout << cnt;
		return 0;
	}
	if(e != 1)
	{
		cout << -1;
		return 0;
	}
	vector <pair <int, int> > vec;
	vector <pair <int, int> > vec1;
	int ans = n - 1;
	for(int i = n - 1; i >= 0; i--)
	{
		if(a[i] != 1 && (vec.size() == 0 || __gcd(vec[0].first, a[i]) != a[i]))
		{
			vec1.push_back({a[i], i});
		}
		for(int j = 0; j < vec.size(); j++)
		{
			if(__gcd(vec[j].first, a[i]) == 1)
			{
				continue;
			}
			if(j != vec.size() - 1 && __gcd(vec[j].first, a[i]) == __gcd(vec[j + 1].first, a[i]))
			{
				continue;
			}
			vec1.push_back({__gcd(vec[j].first, a[i]), vec[j].second});
		}
		vec.clear();
		for(int j =0; j < vec1.size(); j++)
		{
			vec.push_back(vec1[j]);
		}
		vec1.clear();
		if(vec.size() == 0)
		{
			ans = 0;
		}
		else if(vec.back().second != n - 1)
		{
			ans = min(ans, vec.back().second + 1 - i);
		}
	}
	cout << ans + n - 1;
    return 0;
}