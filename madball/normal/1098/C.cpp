#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long lint, ll;
typedef long double ld, ldouble;

#define For(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()

#ifdef LOCAL
#pragma comment(linker, "/STACK:16777216")
#endif

lint get_min(lint n, lint wut, lint start = 1, lint level = 1)
{
	lint cur = start;
	lint res = 0;
	for (lint i = 0; n; ++i)
	{
		res += (i + level) * min(n, cur);
		n -= min(n, cur);
		cur *= wut;
	}
	return res;
}

void solve()
{
	lint n, s;
	cin >> n >> s;
	vector<int> par(n);
	if (s < 2 * n - 1 || s > n * (n + 1) / 2)
	{
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
	lint l = 0;
	lint r = n - 1;
	while (l + 1 < r)
	{
		lint m = (l + r) / 2;
		if (get_min(n, m) <= s)
			r = m;
		else
			l = m;
	}
	vector<lint> level_count;
	if (r == 1)
		level_count.resize(n, 1);
	else
	{
		for (lint i = 1; s; ++i)
		{
			level_count.push_back(1);
			while (get_min(n, r, level_count.back(), i) > s)
			{
				++level_count.back();
			}
			n -= level_count.back();
			s -= i * level_count.back();
		}
	}
	vector<vector<int>> vertices_in_level(sz(level_count));
	int cur = 0;
	For(i, sz(level_count))
		For(j, level_count[i])
			vertices_in_level[i].push_back(cur++);
	for (int i = 1; i < sz(level_count); ++i)
	{
		int pointer = 0;
		int counter = 0;
		For(j, level_count[i])
		{
			par[vertices_in_level[i][j]] = vertices_in_level[i - 1][pointer];
			++counter;
			if (counter == r)
			{
				counter = 0;
				++pointer;
			}
		}
	}
	for (int i = 1; i < sz(par); ++i)
		cout << par[i] + 1 << ' ';
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	solve();
#ifdef LOCAL
	printf("\n\n%.3lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}