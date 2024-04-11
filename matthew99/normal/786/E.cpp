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

namespace network_flow
{
	const int max0 = 1000000, max1 = 3000000;

	struct edge
	{
		int id, g, nxt;

		edge() { }
		edge(int _id, int _g, int _nxt): id(_id), g(_g), nxt(_nxt) { }

	};

	int st[max0 + 5], en = 0;
	edge e[max1 + 5];

	inline void add_edge(int x, int y, int z)
	{
		e[en] = edge(y, z, st[x]), st[x] = en++;
	}

	inline void add_biedge(int x, int y, int z) { add_edge(x, y, z), add_edge(y, x, 0); }

	int S, T, N;

	int dis[max0 + 5];
	bool vis[max0 + 5];

	inline bool bfs()
	{
		static int q[max0 + 5];
		int head = 0, rear = 0;
		memset(dis, -1, sizeof(dis[0]) * N);
		memset(vis, 0, sizeof(vis[0]) * N);
		vis[q[rear++] = S] = 1;
		dis[S] = 0;
		while (head != rear)
		{
			int x = q[head++];
			for (int i = st[x]; i != -1; i = e[i].nxt)
			{
				if (!e[i].g) continue;
				int y = e[i].id;
				if (!vis[y])
				{
					dis[y] = dis[x] + 1;
					if (y == T) return 1;
					q[rear++] = y;
					vis[y] = 1;
				}
			}
		}
		return 0;
	}

	int cur[max0 + 5];

	inline int dfs(int x, int flow)
	{
		if (x == T) return flow;
		int res = flow;
		for (int &i = cur[x]; i != -1; i = e[i].nxt)
		{
			if (!e[i].g) continue;
			int y = e[i].id;
			if (dis[y] == dis[x] + 1)
			{
				int F = dfs(y, min(e[i].g, res));
				res -= F;
				e[i].g -= F;
				e[i ^ 1].g += F;
				if (res <= 0) return flow;
			}
		}
		dis[x] = -1;
		return flow - res;
	}

	int work()
	{
		if (S == T) return oo;
		int ret = 0;
		for ( ; bfs(); )
		{
			REP(i, 0, N) cur[i] = st[i];
			ret += dfs(S, oo);
		}
		return ret;
	}

};

using network_flow::st;
using network_flow::en;
using network_flow::work;
using network_flow::vis;
using network_flow::add_edge;
using network_flow::add_biedge;
using network_flow::S;
using network_flow::N;
using network_flow::T;

const int maxn = 20010, max0 = 15;

int n_tree, n_citizen;
vector<int> adj[maxn + 5];

pair<int, int> ed[maxn + 5];

int id_citizen[maxn + 5], id_edge[maxn + 5];
int id[max0][maxn + 5];

int fa[max0][maxn + 5];

int dep[maxn + 5];

void dfs(int x, int f = -1)
{
	fa[0][x] = f;
	for (auto y : adj[x]) if (y != f) dep[y] = dep[x] + 1, dfs(y, x);
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(st, -1, sizeof st), en = 0;
	scanf("%d%d", &n_tree, &n_citizen);
	REP(i, 0, n_tree - 1)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
		ed[i] = mp(u, v);
	}
	dep[0] = 0;
	dfs(0);
	N = 0;
	S = N++, T = N++;
	REP(i, 0, n_tree) if (~fa[0][i]) id[0][i] = N++;
	REP(i, 1, max0) REP(j, 0, n_tree) 
		if (~fa[i - 1][j])
		{
			id[i][j] = N++;
			add_biedge(id[i - 1][j], id[i][j], oo);
			add_biedge(id[i - 1][fa[i - 1][j]], id[i][j], oo);
			fa[i][j] = fa[i - 1][fa[i - 1][j]];
		}
		else fa[i][j] = fa[i - 1][j];
	REP(i, 0, n_tree - 1)
	{
		int u = ed[i].x, v = ed[i].y;
		if (fa[0][u] != v) swap(u, v);
		id_edge[i] = N++;
		add_biedge(S, id_edge[i], 1);
		add_biedge(id_edge[i], id[0][u], oo);
	}
	REP(i, 0, n_citizen)
	{
		int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		id_citizen[i] = N++;
		add_biedge(id_citizen[i], T, 1);
		if (dep[x] > dep[y]) swap(x, y);
		for (int j = 0; dep[x] != dep[y]; ++j) if ((dep[y] - dep[x]) >> j & 1) add_biedge(id[j][y], id_citizen[i], oo), y = fa[j][y];
		int s = max0 - 1;
		while (x != y)
		{
			for ( ; s && fa[s][x] == fa[s][y]; --s); 
			add_biedge(id[s][x], id_citizen[i], oo);
			add_biedge(id[s][y], id_citizen[i], oo);
			x = fa[s][x];
			y = fa[s][y];
		}
	}
	printf("%d\n", work());
	vector<int> cut_e, cut_c;
	REP(i, 0, n_tree - 1) if (!vis[id_edge[i]]) cut_e.pb(i);
	REP(i, 0, n_citizen) if (vis[id_citizen[i]]) cut_c.pb(i);
	printf("%d", SZ(cut_c));
	for (auto u : cut_c) printf(" %d", u + 1);
	printf("\n");
	printf("%d", SZ(cut_e));
	for (auto u : cut_e) printf(" %d", u + 1);
	printf("\n");
	return 0;
}