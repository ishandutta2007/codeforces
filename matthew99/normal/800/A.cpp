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

const int maxn = 100100;

int n, p;
pair<int, int> a[maxn + 5];

inline bool check(const double &x)
{
	double tmp = 0;
	REP(i, 0, n) tmp += max(0., a[i].x * x - a[i].y);
	return p * x >= tmp;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &p);
	LL sum = 0;
	REP(i, 0, n) scanf("%d%d", &a[i].x, &a[i].y), sum += a[i].x;
	if (sum <= p) printf("-1\n");
	else
	{
		double l = 0, r = 1e18;
		REP(i, 0, 100)
		{
			double mid = (l + r) / 2;
			if (check(mid)) l = mid;
			else r = mid;
		}
		printf("%.15f\n", l);
	}
	return 0;
}