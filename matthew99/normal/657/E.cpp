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

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int Mod = 1e9 + 7;

const int oo = 0x3f3f3f3f;

const int maxn = 300000, max0 = 19;

struct edge
{
	int id, nxt;

	edge() { }
	edge(int _id, int _nxt): id(_id), nxt(_nxt) { }

};

edge e[(maxn << 1) + 5];
int st[maxn + 5], en = 0;

inline void add_edge(int x, int y) { e[en] = edge(y, st[x]), st[x] = en++; }
inline void add_biedge(int x, int y) { add_edge(x, y), add_edge(y, x); }

int n;

int tot;
int fa[max0][maxn + 5];
int dfn[maxn + 5], End[maxn + 5];
int dep[maxn + 5];

int bel[maxn + 5];

void dfs(int x, int id)
{
	bel[x] = id;
	dfn[x] = tot++;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == fa[0][x]) continue;
		fa[0][y] = x;
		dep[y] = dep[x] + 1;
		dfs(y, id);
	}
	End[x] = tot;
}

int lca(int x, int y)
{
	if (bel[x] != bel[y]) return -1;
	if (dep[x] > dep[y]) swap(x, y);
	for (int i = 0; dep[x] != dep[y]; ++i) if ((dep[y] - dep[x]) >> i & 1) y = fa[i][y];
	int s = max0 - 1;
	while (x != y)
	{
		for ( ; s && fa[s][x] == fa[s][y]; --s);
		x = fa[s][x];
		y = fa[s][y];
	}
	return x;
}

inline bool cmp(int x, int y)
{
	return dfn[x] < dfn[y];
}

int belong[maxn + 5];

namespace SCC
{
	struct edge
	{
		int id, nxt;

		edge() { }
		edge(int _id, int _nxt): id(_id), nxt(_nxt) { }

	};

	edge e[(maxn << 1) + 5];
	int st[maxn + 5], en = 0;

	inline void add_edge(int x, int y) { e[en] = edge(y, st[x]), st[x] = en++; }
	inline void add_biedge(int x, int y) { add_edge(x, y), add_edge(y, x); }

	int tot = 0;

	bool in[maxn + 5];

	int N;
	int belong[maxn + 5];

	int dfn[maxn + 5], low[maxn + 5];

	int stk[maxn + 5];

	void dfs(int x, int f = -1)
	{
		int tmp = tot;
		stk[dfn[x] = low[x] = tot++] = x;
		in[x] = 1;
		for (int i = st[x]; ~i; i = e[i].nxt)
		{
			if (i == f) continue;
			int y = e[i].id;
			if (!~dfn[y]) dfs(y, i ^ 1), chkmin(low[x], low[y]);
			else if (in[y]) chkmin(low[x], dfn[y]);
		}
		if (dfn[x] == low[x])
		{
			while (tot != tmp)
			{
				--tot;
				in[stk[tot]] = 0;
				belong[stk[tot]] = N;
			}
			++N;
		}
	}
}

int fa0[maxn + 5];

inline int get(int x) { return fa0[x] == x ? x : fa0[x] = get(fa0[x]); }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m, qn;
	memset(SCC::st, -1, sizeof SCC::st), SCC::en = 0;
	scanf("%d%d%d", &n, &m, &qn);
	vector<pair<int, int> > ed;
	REP(i, 0, m)
	{
		int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		ed.pb(mp(x, y));
		SCC::add_edge(x, y), SCC::add_edge(y, x);
	}
	SCC::tot = SCC::N = 0;
	memset(SCC::dfn, -1, sizeof SCC::dfn);
	REP(i, 0, n) if (!~SCC::dfn[i]) SCC::dfs(i);
	memcpy(belong, SCC::belong, sizeof belong);
	memset(st, -1, sizeof st), en = 0;
	for (auto x : ed) if (belong[x.x] != belong[x.y]) add_edge(belong[x.x], belong[x.y]), add_edge(belong[x.y], belong[x.x]);
	dep[0] = 0;
	memset(fa[0], -1, sizeof fa[0]);
	REP(i, 0, n) if (!~fa[0][i]) dfs(i, i);
	REP(i, 1, max0) REP(j, 0, n)
		if (fa[i - 1][j] == -1) fa[i][j] = fa[i - 1][j];
		else fa[i][j] = fa[i - 1][fa[i - 1][j]];
	int R = 0;
	REP(i, 0, qn)
	{
		int n0, m0;
		scanf("%d%d", &n0, &m0);
		vector<int> v0;
		v0.resize(n0);
		REP(i, 0, n0) scanf("%d", &v0[i]), --v0[i], (v0[i] += R) %= n, v0[i] = belong[v0[i]];
		vector<int> v(v0);
		vector<pair<int, int> > all;
		REP(i, 0, m0)
		{
			int x, y;
			scanf("%d%d", &x, &y), --x, --y;
			(x += R) %= n, (y += R) %= n;
			x = belong[x], y = belong[y];
			all.pb(mp(x, y));
			v.pb(x), v.pb(y);
		}
		sort(ALL(v), cmp);
		v.resize(unique(ALL(v)) - v.begin());
		REP(i, 0, SZ(v) - 1) 
		{
			int tmp = lca(v[i], v[i + 1]);
			if (~tmp) v.pb(tmp);
		}
		sort(ALL(v), cmp);
		v.resize(unique(ALL(v)) - v.begin());
		int N = SZ(v);
		REP(i, 0, N) SCC::st[v[i]] = -1; SCC::en = 0;
		static int stk[maxn + 5];
		int tot = 0;
		REP(i, 0, N)
		{
			int x = v[i];
			while (tot && !(dfn[stk[tot - 1]] <= dfn[x] && dfn[x] < End[stk[tot - 1]])) --tot;
			if (tot) SCC::add_biedge(x, stk[tot - 1]);
			stk[tot++] = x;
		}
		for (auto x : all) SCC::add_biedge(x.x, x.y);
		SCC::tot = SCC::N = 0;
		REP(i, 0, N) SCC::dfn[v[i]] = -1;
		REP(i, 0, N) if (!~SCC::dfn[v[i]]) SCC::dfs(v[i]);
		bool ret = 1;
		REP(i, 1, SZ(v0)) if (SCC::belong[v0[i]] != SCC::belong[v0[0]]) { ret = 0; break; }
		puts(ret ? "YES" : "NO");
		if (ret) (R += i + 1) %= n;
	}
	return 0;
}