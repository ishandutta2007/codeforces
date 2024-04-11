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

	const int max0 = 3000000, max1 = 10000000;

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

	inline int work()
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

const int maxn = 10100;

int n, qn;

struct node;

node *newnode();
node *copy(node *x);

struct node
{
	int id;
	int link;

	node *c[2];

	bool has, con;

	node(): has(0), con(0) { memset(c, 0, sizeof c); }

	void update()
	{
		has = con;
		REP(i, 0, 2) if (c[i] && c[i]->has) has = 1;
	}

	void flag_label()
	{
		if (!con) add_biedge(id, link, oo);
		has = con = 1;
	}

};

const int max0 = 100000;

node *nd_pool;
int nd_res = 0;

inline node *newnode()
{
	if (!nd_res) nd_pool = new node[max0], nd_res = max0;
	node *ret = nd_pool + (--nd_res);
	ret->id = N++;
	return ret;
}

inline node *copy(node *x)
{
	node *tmp = newnode();
	int tmpid = tmp->id;
	*tmp = *x;
	tmp->id = tmpid;
	return tmp;
}

void build(node *&rt, int l, int r)
{
	if (!rt) 
	{
		rt = newnode();
		rt->link = N++;
	}
	if (r - l <= 1) 
	{
		add_biedge(rt->link, T, 1);
		return;
	}
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
	REP(i, 0, 2) add_biedge(rt->link, rt->c[i]->link, oo);
}

int seg_x, seg_y, seg_ty;

void clear(node *&rt)
{
	if (!rt->has) return;
	rt = copy(rt);
	if (rt->con) rt->con = 0;
	rt->update();
	if (rt->has) REP(i, 0, 2) if (rt->c[i]) clear(rt->c[i]);
	rt->update();
	REP(i, 0, 2) if (rt->c[i]) add_biedge(rt->id, rt->c[i]->id, oo);
}

void add(node *&rt, int l, int r)
{
	if (seg_x <= l && r <= seg_y)
	{
		if (!seg_ty) 
		{
			clear(rt);
		}
		else rt = copy(rt), rt->flag_label();
		return;
	}
	rt = copy(rt);
	int mid = (l + r) >> 1;
	if (rt->con)
	{
		REP(i, 0, 2) if (rt->c[i])
		{
			rt->c[i] = copy(rt->c[i]);
			rt->c[i]->flag_label();
		}
		rt->con = 0;
	}
	if (seg_x < mid) add(rt->c[0], l, mid);
	if (seg_y > mid) add(rt->c[1], mid, r);
	rt->update();
	REP(i, 0, 2) if (rt->c[i]) add_biedge(rt->id, rt->c[i]->id, oo);
}

vector<pair<int, pair<int, int> > > all[maxn + 5];

node *rt;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(st, -1, sizeof st);
	S = N++, T = N++;
	scanf("%d", &n);
	scanf("%d", &qn);
	build(rt, 0, n);
	rt->flag_label();
	REP(i, 0, qn)
	{
		int ux, uy, vx, vy;
		scanf("%d%d%d%d", &ux, &uy, &vx, &vy), --ux, --uy;
		all[ux].pb(mp(0, mp(uy, vy)));
		all[vx].pb(mp(1, mp(uy, vy)));
	}
	REP(i, 0, n)
	{
		sort(ALL(all[i]));
		reverse(ALL(all[i]));
		for (auto u : all[i])
		{
			seg_x = u.y.x, seg_y = u.y.y, seg_ty = u.x;
			add(rt, 0, n);
		}
		add_biedge(S, rt->id, 1);
	}
	printf("%d\n", work());
	return 0;
}