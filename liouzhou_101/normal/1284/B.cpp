#include <bits/stdc++.h>

using namespace std;

int main()
{

	int n;
	scanf("%d", &n);
	vector<vector<int>> a(n);
	int64_t ans = int64_t(n)*n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; ++i)
	{
		int m;
		scanf("%d", &m);
		for (int j = 0; j < m; ++j)
		{
			int x;
			scanf("%d", &x);
			a[i].push_back(x);
		}
		int flag = 0;
		for (int j = 1; j < m; ++j)
			if (a[i][j - 1] < a[i][j]) flag = 1;
		if (!flag)
		{
			v.push_back({ a[i].front(), a[i].back() });
		}
	}
	vector<int> s(1000010);
	for (auto [x, y] : v)
	{
		s[x] ++;
	}
	for (int i = 1; i < s.size(); ++i) s[i] = s[i - 1] + s[i];
	for (auto [x, y] : v)
	{
		ans -= s[y];
	}
	cout << ans << endl;


	return 0;
}