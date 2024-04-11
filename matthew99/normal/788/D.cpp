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

#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) | rand())
#else
#define LLFORMAT "ll"
#define Rand() (rand())
#endif

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 100100, maxabs = 1e8;

#ifdef matthew99
int n, m;

int allx[maxn + 5], ally[maxn + 5];

inline int get(int *a, int N, int x)
{
	int p = lower_bound(a, a + N, x) - a;
	int ret = oo;
	if (p < N) chkmin(ret, a[p] - x);
	if (p) chkmin(ret, x - a[p - 1]);
	return ret;
}

int cnt = 0;
#endif

inline int query(int x, int y)
{
#ifndef matthew99
	printf("0 %d %d\n", x, y);
	fflush(stdout);
	int ret;
	scanf("%d", &ret);
	return ret;
#else
	assert(abs(x) <= maxabs);
	assert(abs(y) <= maxabs);
	++cnt;
	return min(get(allx, n, x), get(ally, m, y));
#endif
}

vector<int> X, Y;

int Max = -1, Maxp = -1;

inline void workx(int l, int r)
{
	if (l > r) return;
	int mid = (l + r) >> 1;
	int ret = query(mid, Maxp);
	if (!ret) X.pb(mid), ret = 1;
	workx(l, mid - ret);
	workx(mid + ret, r);
}

inline void worky(int l, int r)
{
	if (l > r) return;
	int mid = (l + r) >> 1;
	int ret = query(Maxp, mid);
	if (!ret) Y.pb(mid), ret = 1;
	worky(l, mid - ret);
	worky(mid + ret, r);
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	REP(i, 0, n) scanf("%d", allx + i);
	REP(i, 0, m) scanf("%d", ally + i);
	sort(allx, allx + n);
	sort(ally, ally + m);
#endif
	srand(time(NULL));
	REP(i, 0, 1000)
	{
		int tmp = Rand() % (maxabs << 1) - maxabs;
		if (chkmax(Max, query(tmp, tmp))) Maxp = tmp;
	}
	workx(-maxabs, maxabs);
	worky(-maxabs, maxabs);
	printf("1 %d %d\n", SZ(X), SZ(Y));
	for (auto u : X) printf("%d ", u);
	printf("\n");
	for (auto u : Y) printf("%d ", u);
#ifdef matthew99
	debug("%d\n", cnt);
	sort(ALL(X));
	sort(ALL(Y));
	assert(SZ(X) == n);
	assert(SZ(Y) == m);
	REP(i, 0, n) assert(X[i] == allx[i]);
	REP(i, 0, m) assert(Y[i] == ally[i]);
#endif
	return 0;
}