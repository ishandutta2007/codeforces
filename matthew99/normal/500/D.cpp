#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cctype>
#include <cassert>
#include <ctime>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

const int maxn = 100000;

int n, m;
int fa[maxn + 5];
int dep[maxn + 5];
int sz[maxn + 5];
vector<int> v[maxn + 5];
pair<int, pair<int, int> > e[maxn + 5];
long double w[maxn + 5];

void dfs(const int &S)
{
	int u = S;
	bool flag = 0;
	fa[S] = -1;
	dep[S] = 0;
	while (u != -1)
	{
		if (!flag) sz[u] = 1;
		flag = 1;
		while (!v[u].empty())
		{
			int v = ::v[u][SZ(::v[u]) - 1];
			::v[u].pop_back();
			if (v == fa[u]) continue;
			fa[v] = u;
			dep[v] = dep[u] + 1;
			flag = 0;
			u = v;
			break;
		}
		if (flag)
		{
			int v = u; u = fa[u];
			if (u == -1) break;
			sz[u] += sz[v];
		}
	}
}

long double cnt = 0, tot;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	tot = (long double)n * (n - 1) * (n - 2);
	REP(i, 0, n - 1)
	{
		static int a, b, c;
		scanf("%d%d%d", &a, &b, &c), --a, --b;
		e[i] = mp(c, mp(a, b));
		v[a].pb(b), v[b].pb(a);
	}
	dfs(0);
	REP(i, 0, n - 1)
	{
		if (dep[e[i].y.y] < dep[e[i].y.x]) swap(e[i].y.x, e[i].y.y);
		cnt += e[i].x * (w[i] = 2 * (long double)sz[e[i].y.y] * (sz[0] - sz[e[i].y.y]));
	}
	scanf("%d", &m);
	REP(i, 0, m)
	{
		static int u, v;
		scanf("%d%d", &u, &v), --u;
		long double delta = v - e[u].x; e[u].x = v;
		cnt += delta * w[u];
		printf("%.15lf\n", (double)(cnt * (n - 2) * 3 / tot));
	}
	return 0;
}