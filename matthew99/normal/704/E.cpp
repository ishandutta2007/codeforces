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

#define y0 __y0
#define y1 __y1

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const double eps = 1e-9;

inline int dcmp(const double &x) { return x < -eps ? -1 : x > eps; }

const int maxn = 100100, maxm = 100100;

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

int n, m;

int fa[maxn + 5];
int sz[maxn + 5], Max[maxn + 5], cur[maxn + 5];

int dfs_seq[maxn + 5], dfs_tot;

int dep[maxn + 5];

void dfs(int x)
{
	fa[x] = -1;
	dep[x] = 0;
	int u = x;
	bool flag = 0;
	while (u != -1)
	{
		if (!flag)
		{
			dfs_seq[dfs_tot++] = u;
			sz[u] = 1;
			Max[u] = -1;
			cur[u] = st[u];
			flag = 1;
		}
		for (int &i = cur[u]; i != -1; i = e[i].nxt)
		{
			const int &v = e[i].id;
			if (v == fa[u]) continue;
			dep[v] = dep[u] + 1;
			fa[v] = u;
			u = v;
			i = e[i].nxt;
			flag = 0;
			break;
		}
		if (flag)
		{
			int v = u; u = fa[u];
			if (u != -1)
			{
				sz[u] += sz[v];
				if (Max[u] == -1 || sz[v] > sz[Max[u]]) Max[u] = v;
			}
		}
	}
}

int top[maxn + 5], start[maxn + 5], chain_sz[maxn + 5];

inline int lca(int x, int y)
{
	while (top[x] != top[y])
	{
		if (dep[top[x]] > dep[top[y]]) swap(x, y);
		y = fa[top[y]];
	}
	return dep[x] < dep[y] ? x : y;
}

struct seg
{
	double x0, x1;
	int y0, k;

	seg() { }
	seg(const double &_x0, const double &_x1, int _y0, int _k): x0(_x0), x1(_x1), y0(_y0), k(_k) { }

	inline double val(const double &p) const { return y0 + (p - x0) * k; }

};

vector<seg> all_seg;

inline bool sect(const seg &x, const seg &y, double &ret)
{
	double l = max(x.x0, y.x0), r = min(x.x1, y.x1);
	if (dcmp(l - r) > 0) return 0;
	double u = x.val(l) - y.val(l), v = x.val(r) - y.val(r);
	if (dcmp(u) * dcmp(v) > 0) return 0;
	if (!dcmp(u - v)) ret = l;
	else ret = (-u * r + v * l) / (v - u);
	return 1;
}

inline void query(int x, int y, int t, int c, double per)
{
	int d = lca(x, y);
	double curt = t;
	int len = dep[x] + dep[y] - (dep[d] << 1);
	int cnt = 0;
	while (1)
	{
		double lst = curt;
		int nxt = dep[top[x]] < dep[d] ? d : top[x];
		if (nxt == d) 
		{
			if (dep[x] != dep[nxt])
			{
				curt += (dep[x] - dep[nxt]) * per;
				all_seg.pb(seg(lst, curt, start[top[x]] + dep[x] - dep[top[x]] + 1, -c)); 
			}
			else ++cnt;
			break;
		}
		else
		{
			curt += (dep[x] - dep[nxt] + 1) * per;
			all_seg.pb(seg(lst, curt, start[top[x]] + dep[x] - dep[top[x]] + 1, -c)); 
		}
		x = fa[nxt];
	}
	curt = t + len * per;
	while (1)
	{
		double lst = curt;
		int nxt = dep[top[y]] < dep[d] ? d : top[y];
		if (nxt == d) 
		{
			if (dep[y] != dep[nxt])
			{
				curt -= (dep[y] - dep[nxt]) * per;
				all_seg.pb(seg(curt, lst, start[top[y]] + dep[nxt] - dep[top[y]] + 1, c));
			}
			else ++cnt;
			break;
		}
		else
		{
			curt -= (dep[y] - dep[nxt] + 1) * per;
			all_seg.pb(seg(curt, lst, start[top[y]] + dep[nxt] - dep[top[y]], c));
		}
		y = fa[nxt];
	}
	if (cnt == 2)
	{
		all_seg.pb(seg(curt, curt, start[top[d]] + dep[d] - dep[top[d]] + 1, c));
		return;
	}
}

double ans = 1e100;

struct event
{
	double t;
	int wh;

	event() { }
	event(const double &_t, int _wh): t(_t), wh(_wh) { }

	friend bool operator<(const event &x, const event &y)
	{
		int tmp = dcmp(x.t - y.t);
		if (!tmp) return (x.wh & 1) > (y.wh & 1);
		return tmp < 0;
	}

};

vector<event> all_event;

double now;

struct cmp
{
	bool operator()(int x, int y) const
	{
		int tmp = dcmp(all_seg[x].val(now) - all_seg[y].val(now));
		if (!tmp) return x < y;
		return tmp < 0;
	}
};

set<int, cmp> all;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(st, -1, sizeof st), en = 0;
	scanf("%d%d", &n, &m);
	REP(i, 0, n - 1)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		add_biedge(u, v);
	}
	dfs(0);
	top[0] = 0;
	REP(i, 1, n)
		if (sz[dfs_seq[i]] && Max[fa[dfs_seq[i]]] == dfs_seq[i]) top[dfs_seq[i]] = top[fa[dfs_seq[i]]];
		else top[dfs_seq[i]] = dfs_seq[i];
	REP(i, 0, n) ++chain_sz[top[i]];
	int sum = 0;
	REP(i, 0, n) if (top[i] == i) start[top[i]] = sum, sum += chain_sz[top[i]] + 1;
	REP(i, 0, m)
	{
		int t, c, u, v;
		scanf("%d%d%d%d", &t, &c, &u, &v), --u, --v;
		query(u, v, t, c, 1. / c);
	}
	REP(i, 0, SZ(all_seg))
	{
		all_event.pb(event(all_seg[i].x0, i << 1 | 1));
		all_event.pb(event(all_seg[i].x1, i << 1));
	}
	sort(ALL(all_event));
	double tmp;
	for (auto u : all_event)
	{
		if (dcmp(u.t - ans) >= 0) break;
		now = u.t;
		int id = u.wh >> 1;
		if (u.wh & 1)
		{
			all.insert(id);
			auto p = all.find(id);
			auto nxt = p; ++nxt;
			if (nxt != all.end())
			{
				if (sect(all_seg[*p], all_seg[*nxt], tmp)) chkmin(ans, tmp);
			}
			if (p != all.begin())
			{
				auto pre = p; --pre;
				if (sect(all_seg[*pre], all_seg[*p], tmp)) chkmin(ans, tmp);
			}
		}
		else
		{
			auto p = all.find(id);
			auto nxt = p; ++nxt;
			if (p != all.begin())
			{
				auto pre = p; --pre;
				if (nxt != all.end())
				{
					if (sect(all_seg[*pre], all_seg[*nxt], tmp)) chkmin(ans, tmp);
				}
			}
			all.erase(p);
		}
	}
	if (ans > 1e10) puts("-1");
	else printf("%.15f\n", ans);
	return 0;
}