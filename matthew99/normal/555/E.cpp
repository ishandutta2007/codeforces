#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

template<typename T> T &Read(T &x)
{
	static char c;
	while (!isdigit(c = getchar()));
	x = c - '0';
	while (isdigit(c = getchar())) (x *= 10) += c - '0';
	return x;
}

const int maxn = 200000, maxm = 200000, max0 = 18;

int st[maxn + 5];
int n, m;

struct edge
{
	int id, nxt;

	edge() { }
	edge(const int &_id, const int &_nxt): id(_id), nxt(_nxt) { }
};

int en;
edge e[(maxm << 1) + 5];

inline void add_edge(const int &x, const int &y)
{
	e[en] = edge(y, st[x]), st[x] = en++;
}

int low[maxn + 5], dfn[maxn + 5];
int dn = 0;

int belong[maxn + 5], fa[maxn + 5][max0], dep[maxn + 5];

int stk[maxn + 5], tot = 0;

int cnt = 0;
int N = 0;

void dfs(const int &x, const int &f = -1)
{
	low[x] = dfn[x] = dn++;
	stk[tot++] = x;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		const int &y = e[i].id;
		if (i >> 1 == f) continue;
		if (dfn[y] == -1)
		{
			dfs(y, i >> 1);
			if (dfn[y] == low[y]) fa[belong[y]][0] = x;
			low[x] = min(low[x], low[y]);
		}
		else low[x] = min(low[x], dfn[y]);
	}
	if (dfn[x] == low[x]) 
	{
		while (1)
		{
			belong[stk[--tot]] = N;
			if (stk[tot] == x) break;
		}
		++N;
	}
}

int End[maxn + 5];
vector<int> chd[maxn + 5];
int block[maxn + 5];
int bn = 0;

void dfs0(const int &x)
{
	block[x] = bn;
	dfn[x] = dn++;
	for (auto y : chd[x]) dep[y] = dep[x] + 1, dfs0(y);
	End[x] = dn;
}

int lca(int x, int y)
{
	if (dep[x] > dep[y]) swap(x, y);
	for (int i = 0; dep[x] != dep[y]; ++i) if ((dep[y] - dep[x]) >> i & 1) y = fa[y][i];
	int s = max0 - 1;
	while (x != y)
	{
		for ( ; fa[x][s] == fa[y][s] && s; --s);
		x = fa[x][s];
		y = fa[y][s];
	}
	return x;
}

int c0[maxn + 5], c1[maxn + 5];

void add(int *c, const int &x, const int &y)
{
	for (int i = x + 1; i <= n; i += i & -i) c[i] += y;
}

int query(int *c, const int &x)
{
	int ret = 0;
	for (int i = x; i > 0; i -= i & -i) ret += c[i];
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(st, -1, sizeof st), en = 0;
	static int qn;
	scanf("%d%d%d", &n, &m, &qn);
	REP(i, 0, m)
	{
		static int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		add_edge(x, y);
		add_edge(y, x);
	}
	memset(dfn, -1, sizeof dfn);
	memset(fa, -1, sizeof fa);
	REP(i, 0, n) if (dfn[i] == -1) dfs(i);
	dn = 0;
	REP(i, 0, N) if (fa[i][0] != -1) chd[fa[i][0] = belong[fa[i][0]]].pb(i);
	REP(i, 1, max0)
		REP(j, 0, N)
			if (fa[j][i - 1] == -1) fa[j][i] = fa[j][i - 1];
			else fa[j][i] = fa[fa[j][i - 1]][i - 1];
	dn = 0;
	bn = 0;
	REP(i, 0, N) if (fa[i][0] == -1) dep[i] = 0, dfs0(i), ++bn;
	REP(i, 0, qn)
	{
		static int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		u = belong[u], v = belong[v];
		if (block[u] != block[v]) EXIT("No\n");
		if (u == v) continue;
		int d = lca(u, v);
		add(c0, dfn[u], 1);
		add(c0, dfn[d], -1);
		add(c1, dfn[v], 1);
		add(c1, dfn[d], -1);
	}
	REP(i, 0, N)
		if (query(c0, End[i]) - query(c0, dfn[i]) && query(c1, End[i]) - query(c1, dfn[i])) EXIT("No\n");
	printf("Yes\n");
	return 0;
}