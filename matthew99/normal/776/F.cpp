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

const int maxn = 100100;

int n, m;

vector<int> adj[maxn + 5];
vector<int> li[maxn + 5];

int N = 0;
vector<int> all[maxn + 5];
map<pair<int, int>, int> id;

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

inline void add_biedge(int x, int y)
{
	add_edge(x, y), add_edge(y, x);
}

int sz[maxn + 5];
int Max[maxn + 5];
int dfs_seq[maxn + 5], dfs_tot = 0;

void pre_dfs(int x, int f = -1)
{
	dfs_seq[dfs_tot++] = x;
	sz[x] = 1;
	Max[x] = 0;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == f) continue;
		pre_dfs(y, x);
		sz[x] += sz[y];
		chkmax(Max[x], sz[y]);
	}
}

int belong[maxn + 5];

bool del_edge(int x, int y)
{
	for (int *i = st + x; *i != -1; i = &e[*i].nxt)
		if (e[*i].id == y)
		{
			*i = e[*i].nxt;
			return 1;
		}
	return 0;
}

void work(int rt, int d = 0)
{
	dfs_tot = 0;
	pre_dfs(rt);
	int x = -1;
	REP(i, 0, dfs_tot)
	{
		int y = dfs_seq[i];
		chkmax(Max[y], sz[rt] - sz[y]);
		if (x == -1 || Max[y] < Max[x]) x = y;
	}
	belong[x] = d;
	for (int i = st[x]; ~i; i = e[i].nxt)
	{
		assert(del_edge(e[i].id, x));
		work(e[i].id, d + 1);
	}
}

vector<int> sorted[maxn + 5];

set<pair<int, int> > vis;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) adj[i].pb((i + 1) % n);
	REP(i, 0, m)
	{
		int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		adj[x].pb(y), adj[y].pb(x);
	}
	REP(i, 0, n)
	{
		li[i].clear();
		for (auto j : adj[i]) li[i].pb(j), li[i].pb(j + n);
		sort(ALL(li[i]));
	}
	REP(i, 0, n) for (auto j : adj[i]) if (!vis.count(mp(i, j)))
	{
		int u = i, v = j;
		vis.insert(mp(u, v));
		vector<int> cur;
		cur.pb(u);
		while (v != i)
		{
			cur.pb(v);
			int p = lower_bound(ALL(li[v]), u + n) - li[v].begin();
			int nxt = li[v][p - 1] % n;
			u = v, v = nxt;
			vis.insert(mp(u, v));
		}
		all[N++] = cur;
	}
	static int pos[maxn + 5], rk[maxn + 5];
	REP(i, 0, N) pos[i] = i, sorted[i] = all[i], sort(ALL(sorted[i]), greater<int>());
	sort(pos, pos + N, [&](int x, int y) { return sorted[x] < sorted[y]; });
	REP(i, 0, N) rk[pos[i]] = i;
	REP(i, 0, N) REP(j, 0, SZ(all[i])) id[mp(all[i][j], all[i][(j + 1) % SZ(all[i])])] = rk[i];
	memset(st, -1, sizeof st), en = 0;
	REP(i, 0, n) for (auto j : adj[i]) if ((j - i + n) % n != 1)
	{
		int x = id[mp(i, j)];
		int y = id[mp(j, i)];
		if (x < y) add_biedge(x, y);
	}
	work(0);
	REP(i, 0, N) printf("%d ", belong[i] + 1);
	printf("\n");
	return 0;
}