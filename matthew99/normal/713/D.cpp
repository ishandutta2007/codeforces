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

const int maxn = 1010, maxt = 1e6 + 10;

int n, m;
int a[maxn + 5][maxn + 5];

int sum[maxn + 5][maxn + 5];
int Max[maxn + 5][maxn + 5];

vector<pair<int, int> > all[maxn + 5];

pair<pair<int, int>, pair<int, int> > q[maxt + 5];
int ans[maxt + 5];

int id[maxt + 5];

int fen[maxn + 5][maxn + 5];

inline void add(int x, int y, int w)
{
	for (int i = x + 1; i <= n; i += i & -i) for (int j = y + 1; j <= m; j += j & -j) fen[i][j] += w;
}

inline int query(int x, int y)
{
	int ret = 0;
	for (int i = x; i > 0; i -= i & -i) for (int j = y; j > 0; j -= j & -j) ret += fen[i][j];
	return ret;
}

inline int query(int x0, int y0, int x1, int y1)
{
	if (x0 >= x1 || y0 >= y1) return 0;
	return query(x1, y1) - query(x0, y1) - query(x1, y0) + query(x0, y0);
}

inline void work(int l, int r, int l0, int r0)
{
	if (l0 == r0) return;
	if (r - l <= 1)
	{
		REP(i, l0, r0) ans[id[i]] = l;
		return;
	}
	int mid = (l + r) >> 1;
	memset(sum, 0, sizeof sum);
	REP(i, mid, r) for (auto x : all[i]) add(x.x, x.y, 1);
	static int tmp[maxt + 5];
	int u = l0, v = r0;
	REP(i, l0, r0)
	{
		if (!query(q[id[i]].x.x, q[id[i]].x.y, q[id[i]].y.x - mid + 1, q[id[i]].y.y - mid + 1)) tmp[u++] = id[i];
		else tmp[--v] = id[i];
	}
	REP(i, l0, r0) id[i] = tmp[i];
	work(l, mid, l0, u); 
	REP(i, mid, r) for (auto x : all[i]) add(x.x, x.y, -1);
	work(mid, r, u, r0); 
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) REP(j, 0, m) scanf("%d", a[i] + j);
	REP(i, 0, n) REP(j, 0, m) sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + a[i][j];
	REP(i, 0, n) REP(j, 0, m)
	{
		int l = 0, r = n;
		while (l < r)
		{
			int mid = (l + r + 1) >> 1;
			if (i + mid > n || j + mid > m || sum[i + mid][j + mid] - sum[i][j + mid] - sum[i + mid][j] + sum[i][j] != mid * mid) r = mid - 1;
			else l = mid;
		}
		Max[i][j] = l;
		all[Max[i][j]].pb(mp(i, j));
	}
	int qn;
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		scanf("%d%d%d%d", &q[i].x.x, &q[i].x.y, &q[i].y.x, &q[i].y.y);
		--q[i].x.x, --q[i].x.y;
		id[i] = i;
	}
	work(0, n + 1, 0, qn);
	REP(i, 0, qn) printf("%d\n", ans[i]);
	return 0;
}