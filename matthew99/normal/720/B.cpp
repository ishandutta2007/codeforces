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
	const int max0 = 100000, max1 = 100000;

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

	inline bool bfs()
	{
		static int q[max0 + 5];
		static bool vis[max0 + 5];
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

}

using network_flow::st;
using network_flow::en;
using network_flow::work;
using network_flow::add_edge;
using network_flow::add_biedge;
using network_flow::S;
using network_flow::N;
using network_flow::T;

const int maxn = 10100, maxm = maxn << 1;

int n, m;
vector<pair<int, int> > adj[maxn + 5];

int dfn[maxn + 5], dfs_cnt;
int belong[maxm + 5];

int pre[maxn + 5];
int dfs_fa[maxn + 5];

int lim[maxn + 5];

void dfs(int x)
{
	dfn[x] = dfs_cnt++;
	for (auto ee : adj[x])
	{
		int y = ee.x, id = ee.y;
		if (id == dfs_fa[x]) continue;
		if (dfn[y] == -1) dfs_fa[y] = id, pre[y] = x, dfs(y);
		else if (dfn[y] < dfn[x])
		{
			int u = x;
			lim[N] = 0;
			belong[id] = N;
			do
			{
				++lim[N];
				belong[dfs_fa[u]] = N;
				u = pre[u];
			}while (u != y);
			++N;
		}
	}
}

int col[maxm + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, m)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w), --u, --v;
		belong[i] = 2;
		col[i] = w - 1;
		adj[u].pb(mp(v, i));
		adj[v].pb(mp(u, i));
	}
	pre[0] = dfs_fa[0] = -1;
	dfs_cnt = 0;
	S = 0, T = 1;
	lim[2] = oo;
	N = 3;
	memset(dfn, -1, sizeof dfn);
	dfs(0);
	memset(st, -1, sizeof st);
	REP(i, 2, N) add_biedge(i, T, lim[i]);
	REP(i, 0, m) add_biedge(S, N + i, 1);
	REP(i, 0, m) add_biedge(N + col[i], belong[i], 1);
	N += m;
	printf("%d\n", work());
	return 0;
}