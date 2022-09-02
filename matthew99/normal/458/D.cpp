#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cctype>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int maxn = 310;

const double MAXANS = 1e99;

double C[maxn + 5][maxn + 5];
double P[maxn * maxn + 5];

double ans = 0;

inline void prepare()
{
	REP(i, 0, maxn + 1)
	{
		C[i][0] = 1;
		REP(j, 1, i + 1) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}
}

int main()
{
	prepare();
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	double tmp = 1;
	REP(i, 0, min(k + 1, maxn * maxn + 3))
	{
		P[i] = tmp;
		tmp /= m - i;
		tmp *= k - i;
	}
	REP(i, 0, n + 1) REP(j, 0, n + 1) ans += C[n][i] * C[n][j] * P[(i + j) * n - i * j];
	chkmin(ans, MAXANS);
	printf("%.15f\n", ans);
	return 0;
}