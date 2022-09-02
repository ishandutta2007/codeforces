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

const int Mod = 1e9 + 7;
const int maxn = 100000, maxm = 100000;

struct edge
{
	int id, nxt;

	edge() { }
	edge(const int &_id, const int &_nxt): id(_id), nxt(_nxt) { }
};

int st[maxn + 5];
edge e[(maxm << 1) + 5];
int en = 0;

inline void add_edge(const int &x, const int &y)
{
	e[en] = edge(y, st[x]), st[x] = en++;
}

int n, m;

int col[maxn + 5];

int fa[maxn + 5];

pair<int, int> ed[maxm + 5];
int M = 0;

int get(const int &x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }

inline void init()
{
	scanf("%d%d", &n, &m);
	memset(col, -1, sizeof col);
	REP(i, 0, n) fa[i] = i;
	REP(i, 0, m)
	{
		static int x, y, z;
		scanf("%d%d%d", &x, &y, &z), --x, --y;
		if (!z) ed[M++] = mp(x, y);
		else
		{
			x = get(x), y = get(y);
			fa[x] = y;
		}
	}
	memset(st, -1, sizeof st), en = 0;
	REP(i, 0, M) ed[i].x = get(ed[i].x), ed[i].y = get(ed[i].y), add_edge(ed[i].x, ed[i].y), add_edge(ed[i].y, ed[i].x);
}

bool vis[maxn + 5];

bool coloring(const int &x, const int &c = 0)
{
	if (vis[x])
	{
		if (col[x] != c) return 0;
		return 1;
	}
	col[x] = c;
	vis[x] = 1;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		const int &y = e[i].id;
		if (!coloring(y, !c)) return 0;
	}
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	int ans = 1;
	bool flag = 0;
	REP(i, 0, n) if (get(i) == i && !vis[i])
	{
		if (!coloring(i)) EXIT("0\n");
		if (flag) (ans <<= 1) %= Mod;
		else flag = 1;
	}
	printf("%d\n", ans);
	return 0;
}