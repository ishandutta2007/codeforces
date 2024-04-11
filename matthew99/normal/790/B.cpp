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

int n, K;

int dep[maxn + 5];
int sz[maxn + 5];
int sz_mod[maxn + 5][5];
LL lca_mod[maxn + 5][5][5];

vector<int> adj[maxn + 5];

LL ans = 0;

void dfs(int x, int f = -1)
{
	sz[x] = 1;
	sz_mod[x][dep[x] % K] = 1;
	for (auto y : adj[x]) if (y != f)
	{
		dep[y] = dep[x] + 1;
		dfs(y, x);
		sz[x] += sz[y];
		REP(i, 0, K) REP(j, 0, i + 1)
		{
			lca_mod[x][i][j] += (LL)sz_mod[x][i] * sz_mod[y][j];
			if (i != j) lca_mod[x][i][j] += (LL)sz_mod[x][j] * sz_mod[y][i];
		}
		REP(i, 0, K) sz_mod[x][i] += sz_mod[y][i];
	}
	REP(i, 1, K) REP(j, 1, K - i + 1)
	{
		int u = (dep[x] + i) % K, v = (dep[x] + j) % K;
		if (u >= v) ans -= lca_mod[x][u][v];
	}
	ans += (LL)sz_mod[x][dep[x] % K] * (n - sz[x]);
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	REP(i, 0, n - 1)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].pb(v), adj[v].pb(u);
	}
	dep[0] = 0;
	dfs(0);
	cout << ans << endl;
	return 0;
}