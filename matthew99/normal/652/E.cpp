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

const int oo = 0x3f3f3f3f;

const int maxn = 300000, maxm = 300000;

struct edge
{
	int id, g, nxt;

	edge() { }
	edge(int _id, int _g, int _nxt): id(_id), g(_g), nxt(_nxt) { }

};

edge e[(maxm << 1) + 5];
int en, st[maxn + 5];

inline void add_edge(int x, int y, int z) { e[en] = edge(y, z, st[x]), st[x] = en++; }
inline void add_biedge(int x, int y, int z) { add_edge(x, y, z), add_edge(y, x, z); }

int n, m;

int tot = 0;

bool in[maxn + 5];

int N;
int belong[maxn + 5];

int stk[maxn + 5];

int dfn[maxn + 5], low[maxn + 5];

int fa[maxn + 5], dep[maxn + 5];

bool has[maxn + 5], w[maxn + 5];

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
		fa[N] = e[f].id;
		w[N] = e[f].g;
		++N;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int x, y, z;
	memset(st, -1, sizeof st), en = 0;
	scanf("%d%d", &n, &m);
	REP(i, 0, m)
	{
		scanf("%d%d%d", &x, &y, &z), --x, --y;
		add_biedge(x, y, z);
	}
	memset(dfn, -1, sizeof dfn), tot = 0;
	dfs(0);
	REP(i, 0, N) if (~fa[i]) fa[i] = belong[fa[i]];
	for (int i = N - 1; i >= 0; --i) 
	{
		if (~fa[i]) dep[i] = dep[fa[i]] + 1;
		else dep[i] = 0;
	}
	REP(i, 0, N) has[i] = 0;
	REP(i, 0, n) for (int j = st[i]; ~j; j = e[j].nxt) if (e[j].g && belong[i] == belong[e[j].id]) has[belong[i]] = 1;
	int S, T;
	scanf("%d%d", &S, &T), --S, --T;
	S = belong[S], T = belong[T];
	bool ans = 0;
	while (S != T)
	{
		if (dep[S] > dep[T]) ans |= has[S] | w[S], S = fa[S];
		else ans |= has[T] | w[T], T = fa[T];
	}
	ans |= has[S];
	puts(ans ? "YES" : "NO");
	return 0;
}