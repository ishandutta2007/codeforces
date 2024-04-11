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

const int maxn = 100100;

int n, qn;
vector<int> adj[maxn + 5];

int fa[maxn + 5];
int dep[maxn + 5];

int bel[maxn + 5];
int cnt[maxn + 5];
LL tot[maxn + 5];
LL sumsqr[maxn + 5];

int sz[maxn + 5];

void dfs(int x, int f = -1)
{
	if (~f) dep[x] = dep[f] + 1;
	fa[x] = f;
	sz[x] = 1;
	sumsqr[x] = 0;
	for (auto y : adj[x]) if (y != f)
	{
		dfs(y, x);
		sz[x] += sz[y];
		sumsqr[x] += (LL)sz[y] * (sz[y] - 1);
	}
	sumsqr[x] += (LL)(n - sz[x]) * (n - sz[x] - 1);
}

LL ans;

int get_bel(int x) { return bel[x] == x ? x : bel[x] = get_bel(bel[x]); }

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n - 1)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0);
	ans = 0;
	REP(i, 0, n) 
	{
		bel[i] = i, cnt[i] = 1;
		tot[i] = (LL)cnt[i] * ((LL)(n - cnt[i]) * (n - cnt[i] - 1) - sumsqr[i]) + (LL)cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) + (LL)cnt[i] * (cnt[i] - 1) * (n - cnt[i]) * 2;
		ans += tot[i];
	}
	printf("%" LLFORMAT "d\n", ans);
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		x = get_bel(x), y = get_bel(y);
		while (x != y)
		{
			if (dep[x] < dep[y]) swap(x, y);
			int p = get_bel(fa[x]);
			bel[x] = p;
			sumsqr[p] += sumsqr[x];
			sumsqr[p] -= (LL)(n - sz[x]) * (n - sz[x] - 1);
			sumsqr[p] -= (LL)sz[x] * (sz[x] - 1);
			cnt[p] += cnt[x];
			ans -= tot[x];
			x = p;
		}
		ans -= tot[x];
		tot[x] = (LL)cnt[x] * ((LL)(n - cnt[x]) * (n - cnt[x] - 1) - sumsqr[x]) + (LL)cnt[x] * (cnt[x] - 1) * (cnt[x] - 2) + (LL)cnt[x] * (cnt[x] - 1) * (n - cnt[x]) * 2;
		ans += tot[x];
		printf("%" LLFORMAT "d\n", ans);
	}
	return 0;
}