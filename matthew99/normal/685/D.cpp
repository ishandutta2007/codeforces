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

const int maxn = 100000, maxk = 300;

int n, K;
int v[maxn + 5], vn;
pair<int, int> a[maxn + 5];

int all[maxn + 5][maxk + 5];

LL ans[maxn + 5];
int lst[maxn + 5];
int now[maxn + 5];

int t;

inline void add(int x, int y)
{
	int wh = lower_bound(v, v + vn, x) - v;
	int cur = x;
	REP(i, 0, K)
	{
		int &p = all[wh][cur - v[wh]];
		if (p) ans[p] += LL(t - lst[p]) * now[p], lst[p] = t, --now[p];
		p += y;
		if (p) ans[p] += LL(t - lst[p]) * now[p], lst[p] = t, ++now[p];
		++cur;
		while (wh + 1 < vn && v[wh + 1] <= cur) ++wh;
	}
}

inline void solve()
{
	vector<int> allx;
	REP(i, 0, n) allx.pb(a[i].x), allx.pb(a[i].x + K);
	sort(ALL(allx));
	allx.resize(unique(ALL(allx)) - allx.begin());
	int i = 0, j = 0;
	for (auto cur : allx)
	{
		t = cur;
		while (i < n && a[i].x <= t) add(a[i].y, 1), ++i;
		while (j < n && a[j].x <= t - K) add(a[j].y, -1), ++j;
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	REP(i, 0, n) scanf("%d%d", &a[i].x, &a[i].y), v[i] = a[i].y;
	sort(a, a + n);
	sort(v, v + n);
	vn = unique(v, v + n) - v;
	solve();
	REP(i, 1, n + 1) printf("%I64d ", ans[i]);
	return 0;
}