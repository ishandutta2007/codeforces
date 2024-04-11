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
const int maxm = 100100;

int n, m, qn;
vector<int> adj[maxn + 5];

int sz[maxn + 5];
vector<int> all[maxn + 5];
vector<pair<LL, int> > sum[maxn + 5];

int bel[maxn + 5];
int in[maxn + 5];

int Maxl[maxn + 5], up[maxn + 5];

int fa[maxn + 5];

int dfs_tot = 0;
int dfs_seq[maxn + 5];

void dfs(int x, int f = -1)
{
	dfs_seq[dfs_tot++] = x;
	fa[x] = f;
	for (auto y : adj[x]) if (y != f) dfs(y, x);
}

map<pair<int, int>, double> ans;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &qn);
	REP(i, 0, m)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	memset(bel, -1, sizeof bel);
	REP(i, 0, n) if (!~bel[i])
	{
		dfs_tot = 0;
		dfs(i);

		for (int j = dfs_tot - 1; j >= 0; --j)
		{
			int x = dfs_seq[j];
			for (auto y : adj[x]) if (y != fa[x]) chkmax(Maxl[x], Maxl[y] + 1);
		}
		REP(j, 0, dfs_tot)
		{
			int x = dfs_seq[j];
			vector<int> chd;
			for (auto y : adj[x]) if (y != fa[x]) chd.pb(y);
			int Max = up[x];
			for (auto y : chd)
			{
				chkmax(up[y], Max + 1);
				chkmax(Max, Maxl[y] + 1);
			}
			reverse(ALL(chd));
			Max = up[x];
			for (auto y : chd)
			{
				chkmax(up[y], Max + 1);
				chkmax(Max, Maxl[y] + 1);
			}
			chkmax(Maxl[x], up[x]);
		}

		sz[i] = dfs_tot;
		sum[i].resize(sz[i] + 1);
		in[i] = 0;
		REP(j, 0, dfs_tot)
		{
			int x = dfs_seq[j];
			chkmax(in[i], Maxl[x]);
			bel[x] = i;
			all[i].pb(Maxl[x]);
			sum[i][Maxl[x]].x += Maxl[x];
			sum[i][Maxl[x]].y += 1;
		}
		for (int j = sz[i] - 1; j >= 0; --j)
		{
			sum[i][j].x += sum[i][j + 1].x;
			sum[i][j].y += sum[i][j + 1].y;
		}
	}
	REP(i, 0, qn)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		u = bel[u];
		v = bel[v];
		if (u == v) printf("-1\n");
		else
		{
			if (mp(sz[u], u) < mp(sz[v], v)) swap(u, v);
			if (ans.count(mp(u, v))) printf("%.15f\n", ans[mp(u, v)]);
			else
			{
				double &ret = ans[mp(u, v)];
				int inside = max(in[u], in[v]);
				for (auto l : all[v])
				{
					++l;
					int p = max(0, min(sz[u], inside - l));
					ret += (double)inside * (sz[u] - sum[u][p].y) + (double)l * sum[u][p].y + sum[u][p].x;
				}
				ret /= sz[u];
				ret /= sz[v];
				printf("%.15f\n", ret);
			}
		}
	}
	return 0;
}