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

const int maxn = 200100;

int n, x, y, xa, yb;
LL Lcm;
int a[maxn + 5];

LL K;

inline bool check(int lim)
{
	int cur = 0;
	LL ret = 0;
	REP(i, 0, lim / Lcm)
		ret += a[cur++] * (x + y);
	REP(i, 0, lim / xa - lim / Lcm)
		ret += a[cur++] * x;
	REP(i, 0, lim / yb - lim / Lcm)
		ret += a[cur++] * y;
	return ret >= K;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		REP(i, 0, n) scanf("%d", a + i), a[i] /= 100;
		scanf("%d%d%d%d", &x, &xa, &y, &yb);
		scanf("%lld", &K);
		Lcm = (LL)xa * yb / __gcd(xa, yb);
		if (x < y) swap(x, y), swap(xa, yb);
		sort(a, a + n, greater<int>());
		int l = 0, r = n + 1;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}
		if (l == n + 1) printf("-1\n");
		else printf("%d\n", l);
	}
	return 0;
}