#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long LL;

const int Mod = (int)1e9 + 9;

const int maxn = 4000;

int n, w, b;

int way[maxn + 5][maxn + 5];

int ans = 0;

void init()
{
	scanf("%d%d%d", &n, &w, &b);
}

void solve()
{
	FOR(i, 0, maxn)
	{
		way[i][0] = i == 0;
		FOR(j, 1, i)
			way[i][j] = ((LL)j * way[i - 1][j - 1] + (LL)way[i - 1][j] * (i - 1 + j)) % Mod;
	}
	REP(i, 2, n)
		(ans += way[w][i] * LL(i - 1) % Mod * way[b][n - i] % Mod) %= Mod;
}

void output()
{
	printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	solve();
	output();
	return 0;
}