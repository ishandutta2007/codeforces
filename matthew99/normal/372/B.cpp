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

const int maxn = 40, maxm = 40;

char g[maxn + 5][maxm + 5];
int n, m, qn;

int sum[maxn + 1][maxm + 1];
int ans[maxn + 1][maxm + 1][maxn + 1][maxm + 1];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &qn);
	REP(i, 0, n) scanf("%s", g[i]);
	sum[0][0] = 0;
	REP(i, 1, n + 1) REP(j, 1, m + 1) sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + g[i - 1][j - 1] - '0';
	REP(i, 0, n) REP(j, 0, m) REP(k, i + 1, n + 1) REP(l, j + 1, m + 1) ans[i][j][k][l] = (sum[k][l] - sum[i][l] - sum[k][j] + sum[i][j]) == 0;
	REP(i, 0, n) REP(j, 0, m) REP(k, i + 1, n + 1) REP(l, j + 1, m + 1) ans[i][j][k][l] += ans[i][j][k - 1][l] + ans[i][j][k][l - 1] - ans[i][j][k - 1][l - 1]; 
	for (int i = n - 1; i >= 0; --i) for (int j = m - 1; j >= 0; --j) REP(k, i + 1, n + 1) REP(l, j + 1, m + 1) ans[i][j][k][l] += ans[i + 1][j][k][l] + ans[i][j + 1][k][l] - ans[i + 1][j + 1][k][l]; 
	REP(i, 0, qn)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d), --a, --b;
		printf("%d\n", ans[a][b][c][d]);
	}
	return 0;
}