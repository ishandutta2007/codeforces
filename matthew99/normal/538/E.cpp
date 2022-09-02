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
#include <set>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 200000;

int n;
vector<int> e[maxn + 5];

pair<int, int> dp[maxn + 5];
int sz[maxn + 5];

void dfs(const int &x, const int &player = 0)
{
	dp[x] = mp(0, 0);
	if (!SZ(e[x]))
	{
		dp[x] = mp(1, 1);
		sz[x] = 1;
		return;
	}
	for (auto y : e[x]) dfs(y, player ^ 1), sz[x] += sz[y];
	if (!player)
	{
		for (auto y : e[x]) dp[x].x += sz[y], dp[x].y += dp[y].y;
		int Max = -oo;
		for (auto y : e[x]) Max = max(Max, dp[x].x - sz[y] + dp[y].x);
		dp[x].x = Max;
	}
	else
	{
		dp[x].y = oo;
		for (auto y : e[x]) dp[x].x += dp[y].x - 1, dp[x].y = min(dp[x].y, dp[y].y);
		dp[x].x += 1;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n - 1)
	{
		static int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		e[u].pb(v);
	}
	dfs(0);
	printf("%d %d\n", dp[0].x, dp[0].y);
	return 0;
}