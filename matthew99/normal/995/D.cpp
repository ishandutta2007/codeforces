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

const int maxn = 18;

int n, m;
int a[(1 << maxn) + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	double ans = 0;
	REP(i, 0, 1 << n) scanf("%d", a + i), ans += a[i];
	printf("%.15f\n", ans / (1 << n));
	REP(i, 0, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		ans -= a[x];
		a[x] = y;
		ans += a[x];
		printf("%.15f\n", ans / (1 << n));
	}
	return 0;
}