#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
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

const int maxn = 1010;

int n;
pair<double, double> a[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%lf%lf", &a[i].x, &a[i].y);
	double ans = 1e100;
	REP(i, 0, n)
	{
		auto u = a[i], v = a[(i + 1) % n], w = a[(i + 2) % n];
		chkmin(ans, abs((w.x - u.x) * (v.y - u.y) - (w.y - u.y) * (v.x - u.x)) / sqrt((w.x - u.x) * (w.x - u.x) + (w.y - u.y) * (w.y - u.y)));
	}
	ans /= 2;
	printf("%.15f\n", ans);
	return 0;
}