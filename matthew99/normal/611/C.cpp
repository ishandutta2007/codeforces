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

const int oo = 0x3f3f3f3f;

const int maxn = 500, maxm = 500;

int n, m;
char g[maxn + 5][maxm + 5];

int sum0[maxn + 5][maxm + 5], sum1[maxn + 5][maxm + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) scanf("%s", g[i]);
	REP(i, 0, n)
	{
		REP(j, 0, m)
		{
			if (j + 1 < m && g[i][j] == '.' && g[i][j + 1] == '.') sum0[i + 1][j + 1] = 1;
			if (i + 1 < n && g[i][j] == '.' && g[i + 1][j] == '.') sum1[i + 1][j + 1] = 1;
		}
	}
	REP(i, 1, n + 1) REP(j, 1, m + 1) sum0[i][j] += sum0[i - 1][j] + sum0[i][j - 1] - sum0[i - 1][j - 1], sum1[i][j] += sum1[i - 1][j] + sum1[i][j - 1] - sum1[i - 1][j - 1];
	int qn;
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		int u, v, x, y;
		scanf("%d%d%d%d", &u, &v, &x, &y), --u, --v;
		int ans = 0;
		ans += sum0[x][y - 1] - sum0[u][y - 1] - sum0[x][v] + sum0[u][v];
		ans += sum1[x - 1][y] - sum1[u][y] - sum1[x - 1][v] + sum1[u][v];
		printf("%d\n", ans);
	}
	return 0;
}