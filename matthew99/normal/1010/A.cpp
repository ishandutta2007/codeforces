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

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 1010;

int n, m;
int a[maxn + 5], b[maxn + 5];

inline bool check(double cur)
{
	REP(i, 0, n)
	{
		cur -= (m + cur) / a[i];
		if (cur < 0) return 0;
		cur -= (m + cur) / b[(i + 1) % n];
		if (cur < 0) return 0;
	}
	return 1;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) scanf("%d", a + i);
	REP(i, 0, n) scanf("%d", b + i);
	double l = 0, r = 1.01e9;
	REP(i, 0, 60)
	{
		double mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	if (l > 1.001e9) printf("-1\n");
	else printf("%.15f\n", l);
	return 0;
}