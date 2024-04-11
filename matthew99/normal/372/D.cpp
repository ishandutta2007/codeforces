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

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int Mod = 1e9 + 7;

const int oo = 0x3f3f3f3f;

const int maxn = 100000, max0 = 17;

struct edge
{
	int id, nxt;

	edge() { }
	edge(int _id, int _nxt): id(_id), nxt(_nxt) { }

};

edge e[(maxn << 1) + 5];
int st[maxn + 5], en = 0;

inline void add_edge(int x, int y)
{
	e[en] = edge(y, st[x]), st[x] = en++;
}

int n, K;

int fa[max0][maxn + 5];

int dep[maxn + 5];

inline int lca(int x, int y)
{
	if (dep[x] > dep[y]) swap(x, y);
	for (int i = 0; dep[x] != dep[y]; ++i) if ((dep[y] - dep[x]) >> i & 1) y = fa[i][y];
	int s = max0 - 1;
	while (x != y)
	{
		for ( ; s && fa[s][x] == fa[s][y]; --s);
		x = fa[s][x], y = fa[s][y];
	}
	return x;
}

int dfn[maxn + 5], tot = 0;

void dfs(int x)
{
	dfn[x] = tot++;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == fa[0][x]) continue;
		fa[0][y] = x;
		dep[y] = dep[x] + 1;
		dfs(y);
	}
}

struct cmp
{
	bool operator()(const int &x, const int &y) const
	{
		return dfn[x] < dfn[y];
	}
};

set<int, cmp> now;

inline int calc(int x)
{
	if (now.empty()) return 1;
	auto p = now.upper_bound(x);
	int u = -1, v = -1;
	if (p == now.end()) v = *now.begin();
	else v = *p;
	if (p == now.begin()) u = *now.rbegin();
	else --p, u = *p;
	return dep[x] + dep[lca(u, v)] - dep[lca(u, x)] - dep[lca(x, v)];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(st, -1, sizeof st), en = 0;
	scanf("%d%d", &n, &K);
	REP(i, 0, n - 1)
	{
		int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		add_edge(x, y); 
		add_edge(y, x);
	}
	fa[0][0] = -1;
	dfs(0);
	REP(i, 1, max0)
		REP(j, 0, n)
			if (fa[i - 1][j] == -1) fa[i][j] = fa[i - 1][j];
			else fa[i][j] = fa[i - 1][fa[i - 1][j]];
	set<int, cmp> all;
	int j = 0, sz = 0;
	int ans = 0;
	REP(i, 0, n)
	{
		sz += calc(i);
		now.insert(i);
		while (sz > K)
		{
			assert(j <= i);
			now.erase(j);
			sz -= calc(j);
			++j;
		}
		chkmax(ans, i - j + 1);
	}
	printf("%d\n", ans);
	return 0;
}