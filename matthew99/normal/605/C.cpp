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

const int maxn = 100000, maxm = 100000;

int n, p, q;

pair<int, int> a[maxm + 5];

inline LL cross(int i, int j, int k)
{
	return (LL)(a[j].x - a[i].x) * (a[k].y - a[i].y) - (LL)(a[j].y - a[i].y) * (a[k].x - a[i].x);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &p, &q);
	REP(i, 0, n) scanf("%d%d", &a[i].x, &a[i].y);
	double ans = 1e100;
	REP(i, 0, n) chkmin(ans, max((double)p / a[i].x, (double)q / a[i].y));
	sort(a, a + n);
	static int stk[maxn + 5];
	int stkn = 0;
	REP(i, 0, n)
	{
		while (stkn > 1 && cross(stk[stkn - 2], stk[stkn - 1], i) >= 0) --stkn;
		stk[stkn++] = i;
	}
	REP(i, 0, stkn - 1)
	{
		int x = stk[i], y = stk[i + 1];
		LL det = (LL)a[x].x * a[y].y - (LL)a[x].y * a[y].x;
		if (!det) continue;
		LL x0 = (LL)p * a[y].y - (LL)a[y].x * q;
		LL x1 = (LL)a[x].x * q - (LL)a[x].y * p;
		if (det > 0 && x0 >= 0 && x1 >= 0) chkmin(ans, (double)x0 / det + (double)x1 / det);
		if (det < 0 && x0 <= 0 && x1 <= 0) chkmin(ans, (double)x0 / det + (double)x1 / det);
	}
	printf("%.15f\n", ans);
	return 0;
}