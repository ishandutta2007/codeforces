#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define SZ(x) (int((x).size()))

using namespace std;

const int oo = 0x3f3f3f3f;

const int maxc = 10000;
const int maxn = 6000;
const int max0 = 100000, max1 = 1000000;

struct edge
{
	int id, g, nxt;

	edge() { }
	edge(const int &_id, const int &_g, const int &_nxt): id(_id), g(_g), nxt(_nxt) { }

};

int lim[maxn + 5];
int n;

edge e[max1 + 5];
int en = 0;
int st[max0 + 5], lst[maxn + 5];
vector<pair<int, int> > ve[maxn + 5], tmp_ve[maxn + 5];
int N;
int ans;

int l, r, mid;

void add_edge(const int &x, const int &y, const int &z)
{
	e[en] = edge(y, z, st[x]), st[x] = en++;
}

pair<int, int> fa[maxn + 5];
int Max[maxn + 5], sz[maxn + 5];
vector<int> all;

void dfs(const int &rt)
{
	static int cur[maxn + 5];
	all.clear();
	int u = rt;
	fa[rt] = mp(-1, -1), Max[rt] = 0;
	bool flag = 0;
	while (u != -1)
	{
		if (!flag)
		{
			all.pb(u);
			cur[u] = 0;
			sz[u] = 1;
		}
		flag = 1;
		for (int &i = cur[u]; i != SZ(ve[u]); ++i)
		{
			const int &v = ve[u][i].x;
			if (v == fa[u].x) continue;
			const int &w = ve[u][i].y;
			fa[v] = mp(u, w);
			Max[v] = max(Max[u], w);
			u = v;
			++i;
			flag = 0;
			break;
		}
		if (flag)
		{
			int v = u; u = fa[u].x;
			if (u != -1) sz[u] += sz[v];
		}
	}
}

void init()
{
	scanf("%d", &n);
	REP(i, 0, n - 1)
	{
		static int a, b, c;
		scanf("%d%d%d", &a, &b, &c), --a, --b;
		ve[a].pb(mp(b, c)), ve[b].pb(mp(a, c));
	}
	REP(i, 0, n) scanf("%d", lim + i);
	dfs(0);
	REP(i, 0, n) ve[i].clear();
	memset(lst, -1, sizeof lst);
	N = n;
	REP(i, 0, SZ(all))
	{
		const int &b = all[i];
		if (fa[b].x == -1) continue;
		const int &a = fa[b].x, &c = fa[b].y;
		int tmp = a;
		if (lst[a] != -1)
		{
			tmp = N++;
			ve[lst[a]].pb(mp(tmp, 0)), ve[tmp].pb(mp(lst[a], 0));
			lst[a] = tmp;
		}
		else lst[a] = a;
		ve[tmp].pb(mp(b, c)), ve[b].pb(mp(tmp, c));
	}
}

int res = 0;
int S, T;

void work(const int &rt)
{
	dfs(rt);
	if (SZ(all) == 1) return;
	int Min = oo, Minp = -1;
	REP(i, 0, SZ(all))
	{
		const int &x = all[i];
		if (x == rt) continue;
		int tmp = abs((sz[x] << 1) - sz[rt]);
		if (tmp < Min) Min = tmp, Minp = x;
	}
	const int &G = Minp;
	int faG = fa[G].x;
	int w = fa[G].y;
	ve[faG].erase(find(ve[faG].begin(), ve[faG].end(), mp(G, w)));
	ve[G].erase(find(ve[G].begin(), ve[G].end(), mp(faG, w)));
	N += 2;
	int Vl = N - 2, Vr = N - 1;
	N += 2;
	int vl = N - 2, vr = N - 1;
	dfs(G);
	REP(i, 0, SZ(all))
	{
		const int &x = all[i];
		if (max(Max[x], w) >= mid) add_edge(Vl, x << 1 | 1, oo), add_edge(x << 1 | 1, Vl, 0);
		add_edge(x << 1, Vr, oo), add_edge(Vr, x << 1, 0); 
		if (max(Max[x], w) >= mid) add_edge(x << 1, vl, oo), add_edge(vl, x << 1, 0); 
		add_edge(vr, x << 1 | 1, oo), add_edge(x << 1 | 1, vr, 0);
	}
	dfs(faG);
	REP(i, 0, SZ(all))
	{
		const int &x = all[i];
		if (max(Max[x], w) >= mid) add_edge(Vr, x << 1 | 1, oo), add_edge(x << 1 | 1, Vr, 0);
		add_edge(x << 1, Vl, oo), add_edge(Vl, x << 1, 0); 
		if (max(Max[x], w) >= mid) add_edge(x << 1, vr, oo), add_edge(vr, x << 1, 0); 
		add_edge(vl, x << 1 | 1, oo), add_edge(x << 1 | 1, vl, 0);
	}
	work(G), work(faG);
}

int num[max0 + 5], dis[max0 + 5];

int dfs(const int &x, const int &S, const int &T, const int &flow)
{
	if (x == T) return flow;
	int res = flow;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		const int &y = e[i].id;
		if (e[i].g && dis[y] + 1 == dis[x])
		{
			int F = dfs(y, S, T, min(res, e[i].g));
			res -= F;
			e[i].g -= F, e[i ^ 1].g += F;
			if (res <= 0) return flow;
		}
	}
	if (!--num[dis[x]]) dis[S] = N;
	++num[++dis[x]];
	return flow - res;
}

void max_flow(const int &S, const int &T)
{
	res = 0;
	memset(num, 0, sizeof num);
	memset(dis, 0, sizeof dis);
	for (num[0] = N ; dis[S] < N; res += dfs(S, S, T, oo));
}

void solve()
{
	int tmp = N;
	int l = 0, r = maxc;
	REP(i, 0, tmp) tmp_ve[i] = ve[i];
	while (l < r)
	{
		mid = (l + r + 1) >> 1;
		memset(st, -1, sizeof st);
		REP(i, 0, tmp) ve[i] = tmp_ve[i];
		en = 0;
		N = (tmp << 1) + 2;
		S = N - 2, T = N - 1;
		REP(i, 0, n) add_edge(S, i << 1, 1), add_edge(i << 1, S, 0), add_edge(i << 1 | 1, T, lim[i]), add_edge(T, i << 1 | 1, 0);
		work(0);
		max_flow(S, T);
		if (res >= n) l = mid;
		else r = mid - 1;
	}
	ans = l;
}

void output()
{
	printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	solve();
	output();
	return 0;
}