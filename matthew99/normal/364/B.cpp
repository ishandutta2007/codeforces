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

const int maxn = 50, maxd = 10000;

int n, d;
int a[maxn + 5];
bool f[maxn + 5][maxd * maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &d);
	REP(i, 0, n) scanf("%d", a + i);
	f[0][0] = 1;
	REP(i, 0, n) REP(j, 0, maxd * i + 1) if (f[i][j]) f[i + 1][j] = f[i + 1][j + a[i]] = 1;
	int ans = 0, step = 0;
	for (int i = d; ; i = ans + d, ++step)
	{
		REP(j, i - d + 1, i + 1) if (f[n][j]) ans = j;
		if (ans == i - d) break;
	}
	printf("%d %d\n", ans, step);
	return 0;
}