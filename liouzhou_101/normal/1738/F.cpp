#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> d(n + 1);
	for (int i = 1; i <= n; ++i) cin >> d[i];

	auto query = [&](int x)
	{
		cout << "? " << x << endl;
		int y;
		cin >> y;
		return y;
	};

	vector<int> visited(n + 1);
	vector<int> res(n + 1);
	int color_cnt = 0;
	while (1)
	{
		int x = 0;
		for (int i = 1; i <= n; ++i)
			if (!visited[i] && d[i] >= d[x]) x = i;
		if (x == 0) break;
		vector<int> q = { x };
		int colored_vertex = 0;
		for (int i = 1; i <= d[x]; ++i)
		{
			int y = query(x);
			if (visited[y])
			{
				colored_vertex = y;
				break;
			}
			q.push_back(y);
		}
		int color = colored_vertex == 0 ? ++color_cnt : res[colored_vertex];
		for (auto z : q)
		{
			visited[z] = 1;
			res[z] = color;
		}
	}

	cout << "!";
	for (int i = 1; i <= n; ++i)
		cout << " " << res[i];
	cout << endl;
}

int main()
{
	int tests;
	cin >> tests;
	while (tests--) solve();
	return 0;
}