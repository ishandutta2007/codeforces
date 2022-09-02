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

const int Mod = 1e9 + 7;

const int maxn = 100000;

int n, p;
int l[maxn + 5], r[maxn + 5];

double cnt[maxn + 5], tot[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &p);
	REP(i, 0, n) scanf("%d%d", l + i, r + i), ++r[i], cnt[i] = (r[i] - 1) / p - (l[i] - 1) / p, tot[i] = r[i] - l[i];
	double ans = 0;
	REP(i, 0, n)
	{
		int nxt = (i + 1) % n;
		double b = tot[i] * tot[nxt];
		double a = cnt[i] * tot[nxt] + tot[i] * cnt[nxt] - cnt[i] * cnt[nxt];
		ans += a / b;
	}
	ans *= 2000;
	printf("%.15f\n", ans);
	return 0;
}