#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <ctime>
#include <functional>
#include <cstring>
#include <iomanip>
#include <cassert>
#include <string>

using namespace std;

typedef long long lint, ll;
typedef long double ld, ldouble;

#define For(i, n)  for (int (i) = 0; (i) < (int)(n); (i)++)
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()

const int MAXN = (int)3e5 + 10;
vector<int> graph[MAXN];
lint weight[MAXN];
lint max_sum[MAXN];

lint dfs(int v, int from = -1)
{
	max_sum[v] = weight[v];
	for (auto u : graph[v])
	{
		if (u == from)
			continue;
		lint add = dfs(u, v);
		if (add > 0)
			max_sum[v] += add;
	}
	return max_sum[v];
}

int dfs2(int v, int from, lint mx)
{
	int cnt = 0;
	max_sum[v] = weight[v];
	for (auto u : graph[v])
	{
		if (u == from)
			continue;
		cnt += dfs2(u, v, mx);
		if (max_sum[u] > 0)
			max_sum[v] += max_sum[u];
	}
	if (max_sum[v] == mx)
	{
		cnt++;
		max_sum[v] = 0;
	}
	return cnt;
}

void solve()
{
	int n;
	cin >> n;
	For(i, n)
		cin >> weight[i];
	For(i, n - 1)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	lint mx = dfs(0);
	For(i, n)
		mx = max(mx, max_sum[i]);
	int cnt = dfs2(0, -1, mx);
	cout << mx * cnt << ' ' << cnt << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	solve();
#ifdef LOCAL
	printf("\n\n%.3lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}