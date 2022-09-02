#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef long long LL;

const int maxn = 2000;

int n;
int d[maxn + 5][maxn + 5];

void init()
{
	scanf("%d", &n);
	REP(i, 0, n)
		REP(j, 0, n)
			scanf("%d", &d[i][j]);
	REP(i, 0, n)
		REP(j, 0, n)
			if (i == j && d[i][j]) EXIT("NO\n");
			else if (d[i][j] != d[j][i]) EXIT("NO\n");
			else if (i != j && !d[i][j]) EXIT("NO\n");
}

int f[maxn + 5], sum[maxn + 5];

int deg[maxn + 5];

LL dep[maxn + 5];

bool vis[maxn + 5] = {0};

void get_dep(const int &x)
{
	if (vis[x]) return;
	if (x == 0) return;
	if (f[x] == -1) EXIT("NO\n");
	vis[x] = 1;
	get_dep(f[x]);
	dep[x] = dep[f[x]] + d[f[x]][x];
}

bool vis0[maxn + 5][maxn + 5];
LL dis[maxn + 5][maxn + 5];

LL get_dist(const int &x, const int &y)
{
	if (x == y) return 0;
	if (vis0[x][y]) return dis[x][y];
	vis0[x][y] = 1;
	if (dep[y] > dep[x]) return dis[x][y] = get_dist(x, f[y]) + d[f[y]][y];
	else return dis[x][y] = get_dist(f[x], y) + d[f[x]][x];
}

void solve()
{
	memset(deg, -1, sizeof deg);
	memset(f, -1, sizeof f);
	dep[0] = 0, f[0] = -1;
	REP(l, 0, n)
	{
		int Max = -1;
		REP(i, 0, n)
			if (deg[i] == -1 && (Max == -1 || d[0][i] > d[0][Max])) Max = i;
		REP(i, 0, n)
			if (deg[i] == 0)
			{
				if (d[0][i] == d[0][Max] + d[Max][i])
				{
					f[i] = Max;
					++deg[i];
				}
			}
		deg[Max] = 0;
	}
	memset(dep, 0x3f, sizeof dep);
	REP(i, 0, n) get_dep(i);
	REP(i, 0, n)
		REP(j, 0, n)
			if (get_dist(i, j) != d[i][j]) EXIT("NO\n");
	EXIT("YES\n");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	solve();
	return 0;
}