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

const int maxn = 200100;
const int maxm = 200100;

const int max0 = 18;

int n, m;

struct data
{
	int x, y, w, id;

	data() { }
	data(int _x, int _y, int _w, int _id): x(_x), y(_y), w(_w), id(_id) { }

	friend bool operator<(const data &x, const data &y) { return x.w < y.w; }

};

data e[maxm + 5];

vector<pair<int, int> > adj[maxn + 5];

bool on[maxn + 5];
int pid[maxn + 5];
int ans[maxm + 5];

int pa[maxn + 5];

int get_pa(int x) { return pa[x] == x ? x : pa[x] = get_pa(pa[x]); }

int fa[max0][maxn + 5];
int Max[max0][maxn + 5];

int dfn[maxn + 5], End[maxn + 5];
int dfs_tot;

void dfs(int x, int f = -1)
{
	dfn[x] = dfs_tot++;
	fa[0][x] = f;
	for (auto y : adj[x]) if (y.x != f)
	{
		Max[0][y.x] = e[y.y].w;
		pid[y.x] = y.y;
		dfs(y.x, x);
	}
	End[x] = dfs_tot;
}

inline void find_tree()
{
	REP(i, 0, n) pa[i] = i;
	sort(e, e + m);
	REP(i, 0, m)
	{
		int x = e[i].x, y = e[i].y;
		if (get_pa(x) != get_pa(y))
		{
			on[i] = 1;
			pa[get_pa(x)] = get_pa(y);
			adj[x].pb(mp(y, i)), adj[y].pb(mp(x, i));
		}
		else on[i] = 0;
	}
	dfs(0);
	REP(i, 1, max0)
	{
		REP(j, 0, n) 
		if (~fa[i - 1][j]) fa[i][j] = fa[i - 1][fa[i - 1][j]], Max[i][j] = max(Max[i - 1][j], Max[i - 1][fa[i - 1][j]]);
		else fa[i][j] = fa[i - 1][j], Max[i][j] = Max[i - 1][j];
	}
}

int bel[maxn + 5];

int get_bel(int x) { return bel[x] == x ? x : bel[x] = get_bel(bel[x]); }

inline bool is_anc(int x, int y) { return dfn[x] <= dfn[y] && dfn[y] < End[x]; }

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, m)
	{
		scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w), --e[i].x, --e[i].y;
		e[i].id = i;
	}

	find_tree();

	memset(ans, oo, sizeof ans);
	REP(i, 0, n) bel[i] = i;
	REP(i, 0, m) if (!on[i])
	{
		{
			ans[e[i].id] = 0;
			int u = e[i].x, v = e[i].y;
			REP(k, 0, 2)
			{
				for (int j = max0 - 1; j >= 0; --j) if (~fa[j][u] && !is_anc(fa[j][u], v)) chkmax(ans[e[i].id], Max[j][u] - 1), u = fa[j][u];
				if (!is_anc(u, v)) chkmax(ans[e[i].id], Max[0][u] - 1), u = fa[0][u];
				swap(u, v);
			}
		}

		{
			int u = e[i].x, v = e[i].y;
			REP(k, 0, 2)
			{
				u = get_bel(u);
				while (!is_anc(u, v))
				{
					chkmin(ans[e[pid[u]].id], e[i].w - 1);
					u = bel[u] = get_bel(fa[0][u]);
				}
				swap(u, v);
			}
		}
	}

	REP(i, 0, m) if (ans[i] < oo) printf("%d ", ans[i]); else printf("-1 ");

	return 0;
}