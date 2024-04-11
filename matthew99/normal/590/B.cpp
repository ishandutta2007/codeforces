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

const int maxn = 500000;

int x0, y0, x1, y1;

int v, t;

int vx, vy, wx, wy;

bool check(double T)
{
	double go0 = min((double)t, T), go1 = max(0.0, T - t);
	double x = x1 - go0 * vx - go1 * wx, y = y1 - go0 * vy - go1 * wy;
	return x * x + y * y <= v * v * T * T;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d%d%d%d%d%d%d%d", &x0, &y0, &x1, &y1, &v, &t, &vx, &vy, &wx, &wy);
	x1 -= x0, y1 -= y0;
	double l = 0, r = 1e12;
	while (clock() < 0.9 * CLOCKS_PER_SEC)
	{
		double mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	printf("%.12f\n", l);
	return 0;
}