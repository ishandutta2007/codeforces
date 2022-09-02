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

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 3010;

int pre[maxn + 5][maxn + 5];
int sz[maxn + 5][maxn + 5];

int cur;

int n;
vector<int> adj[maxn + 5];

void dfs(int x, int f = -1)
{
	pre[cur][x] = f;
	sz[cur][x] = 1;
	for (auto y : adj[x]) if (y != f)
	{
		dfs(y, x);
		sz[cur][x] += sz[cur][y];
	}
}

LL dp[maxn + 5][maxn + 5];
bool vis[maxn + 5][maxn + 5];

inline LL work(int x, int y)
{
	if (vis[x][y]) return dp[x][y];
	vis[x][y] = 1;
	if (x == y) return 0;
	return dp[x][y] = (LL)sz[x][y] * sz[y][x] + max(work(x, pre[x][y]), work(y, pre[y][x]));
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n - 1)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	REP(i, 0, n) cur = i, dfs(i);
	LL ans = 0;
	memset(dp, 0, sizeof dp);
	memset(vis, 0, sizeof vis);
	REP(i, 0, n) REP(j, 0, n) chkmax(ans, work(i, j));
	printf("%lld\n", ans);
	return 0;
}