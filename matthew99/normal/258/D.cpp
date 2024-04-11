#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 1000;

int n, m;
double f[maxn + 5][maxn + 5];
double ans = 0;
int a[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n)
		scanf("%d", a + i), --a[i];
	REP(i, 0, n)
		REP(j, 0, n)
			f[i][j] = a[i] > a[j];
	REP(i, 0, m)
	{
		static int a, b;
		scanf("%d%d", &a, &b), --a, --b;
		REP(i, 0, n)
			if (i != a && i != b) f[i][a] = f[i][b] = (f[i][a] + f[i][b]) / 2, f[a][i] = f[b][i] = (f[a][i] + f[b][i]) / 2;
		f[a][b] = f[b][a] = 0.5;
	}
	REP(i, 0, n)
		REP(j, i + 1, n)
			ans += f[i][j];
	printf("%.15lf\n", ans);
	return 0;
}