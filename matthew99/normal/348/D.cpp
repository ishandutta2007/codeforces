#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int Mod = 1000000007;

const int oo = 0x3f3f3f3f;

const int maxn = 3000, maxm = 3000;

int n, m;
char g[maxn + 5][maxm + 5];

int cnt[maxn + 5][maxm + 5];
int dp[maxn + 5][maxm + 5];

int go(int x0, int y0, int x1, int y1)
{
	if (g[x0][y0] == '#' || g[x1][y1] == '#') return 0;
	memset(cnt, 0, sizeof cnt);
	cnt[x0][y0] = 1;
	REP(i, x0, x1 + 1) REP(j, y0, y1 + 1)
	{
		if (i != x0 || j != y0)
		{
			if (g[i][j] == '#') continue;
			cnt[i][j] = 0;
			if (i > x0) cnt[i][j] += cnt[i - 1][j];
			if (j > y0) cnt[i][j] += cnt[i][j - 1];
			cnt[i][j] %= Mod;
		}
	}
	return cnt[x1][y1];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) scanf("%s", g[i]);
	int ans = ((LL)go(0, 1, n - 2, m - 1) * go(1, 0, n - 1, m - 2) - (LL)go(0, 1, n - 1, m - 2) * go(1, 0, n - 2, m - 1)) % Mod;
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}