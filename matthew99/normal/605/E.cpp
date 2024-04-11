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

const int maxn = 1000;

int n;

double p[maxn + 5][maxn + 5];
double ans[maxn + 5];
double tot[maxn + 5];
bool vis[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) REP(j, 0, n) scanf("%lf", p[i] + j), p[i][j] /= 100;
	REP(i, 0, n) ans[i] = 0, tot[i] = 1;
	tot[n - 1] = 0;
	REP(i, 0, n)
	{
		int Minp = -1;
		REP(j, 0, n)
			if (!vis[j] && tot[j] < 1 && (Minp == -1 || (ans[Minp] + 1) / (1 - tot[Minp]) > (ans[j] + 1) / (1 - tot[j]))) Minp = j;
		if (Minp == -1) break;
		vis[Minp] = 1;
		if (Minp != n - 1) (ans[Minp] += 1) /= (1 - tot[Minp]);
		if (!Minp)
		{
			printf("%.15f\n", ans[0]);
			break;
		}
		vis[Minp] = 1;
		REP(j, 0, n)
			if (!vis[j])
			{
				ans[j] += tot[j] * p[j][Minp] * ans[Minp];
				tot[j] *= 1 - p[j][Minp];
			}
	}
	return 0;
}