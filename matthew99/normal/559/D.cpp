#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef long long LL;

const int oo = 0x3f3f3f3f;

template<typename T> bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }

const int maxn = 100000;

typedef pair<LL, LL> point;

int n;
point a[maxn + 5];

inline void init()
{
	scanf("%d", &n);
	REP(i, 0, n) scanf("%I64d%I64d", &a[i].x, &a[i].y), a[i].y += 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	long double ans = 0;
	static long double pw[maxn + 5];
	pw[0] = 1;
	REP(i, 0, n) pw[i + 1] = pw[i] * 0.5;
	long double tot = 1 - pw[n] * ((long double)n * (n + 1) / 2 + 1);
	tot = 1. / 4 / tot;
	REP(i, 1, n - 1)
	{
		long double p = tot * (1 - pw[n - i - 1]);
		REP(j, 0, n)
		{
			int l = j, r = (l + i) % n;
			ans += p * ((double)a[l].x * a[r].y - (double)a[r].x * a[l].y - abs(__gcd(a[l].x - a[r].x, a[l].y - a[r].y)));
		}
		if (clock() > 2.2 * CLOCKS_PER_SEC) break;
		tot /= 2;
	}
	printf("%.15f\n", (double)(ans / 2 + 1));
	return 0;
}