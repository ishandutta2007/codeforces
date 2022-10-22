#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n;
	scanf("%d", &n);
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
	vector<vector<long long>> v(2);
	for (int i = 0; i < n; ++i)
		v[a[i]].push_back(b[i]);
	for (int i = 0; i < 2; ++i)
		sort(v[i].begin(), v[i].end());

	auto go = [&]()
	{
		long long res = 0;
		if (v[0].size() == v[1].size())
			res -= min(v[0].front(), v[1].front());
		while (!v[0].empty() && !v[1].empty())
		{
			res += (v[0].back() + v[1].back()) * 2;
			v[0].pop_back();
			v[1].pop_back();
		}
		for (auto x : v[0]) res += x;
		for (auto x : v[1]) res += x;
		return res;
	};

	printf("%lld\n", go());
}

int main()
{
	int tests;
	scanf("%d", &tests);
	while (tests--) solve();
	return 0;
}