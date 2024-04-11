#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <string>

using namespace std;

struct quadra
{
	int t, r, c, x;
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int> > a(n, vector<int>(m, 0));
	vector<quadra> que;
	for (int cc = 0; cc < q; cc++)
	{
		int t = 0, r = 0, c = 0, x = 0;
		cin >> t;
		if (t == 3)
			cin >> r >> c >> x;
		if (t == 2)
			cin >> c;
		if (t == 1)
			cin >> r;
		que.push_back({ t, r, c, x });
	}
	reverse(que.begin(), que.end());
	for (int cc = 0; cc < q; cc++) 
	{
		int t, r, c, x;
		t = que[cc].t, r = que[cc].r, c = que[cc].c, x = que[cc].x;
		if (t == 3)
		{
			a[--r][--c] = x;
		}
		if (t == 2)
		{
			for (int i = n - 1; i > 0; i--)
			{
				swap(a[i][c - 1], a[(i + 1) % n][c - 1]);
			}
		}
		if (t == 1)
		{
			for (int i = m - 1; i > 0; i--)
			{
				swap(a[r - 1][i], a[r - 1][(i + 1) % m]);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}