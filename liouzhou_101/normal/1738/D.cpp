#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n;
	scanf("%d", &n);
	vector<int> b(n + 1);
	int k = 0;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &b[i]);
		if (b[i] > i) k = i;
	}

	vector<vector<int>> v(n + 2);
	for (int i = 1; i <= n; ++i)
		v[b[i]].push_back(i);

	int root = v[0].size() ? 0 : n + 1;

	vector<int> q = { root };
	for (int i = 0; i < q.size(); ++i)
	{
		int x = q[i];
		sort(v[x].begin(), v[x].end(), [&](int a, int b)
			{
				return v[a].size() < v[b].size();
			});
		for (auto y : v[x])
			q.push_back(y);
	}

	printf("%d\n", k);
	assert(q.size() == n + 1);
	for (int i = 1; i < (int)q.size(); ++i)
	{
		if (i > 1) printf(" ");
		printf("%d", q[i]);
	}
	puts("");
}

int main()
{
	int tests;
	scanf("%d", &tests);
	while (tests--) solve();
	return 0;
}