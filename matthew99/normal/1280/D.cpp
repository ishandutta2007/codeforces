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

const LL OO = 0x3f3f3f3f3f3f3f3fLL;
const int oo = 0x3f3f3f3f;

const int maxn = 3010;

int n, m;
int a[maxn + 5];
vector<int> adj[maxn + 5];

int sz[maxn + 5];
LL sum[maxn + 5];
pair<int, LL> dp[maxn + 5][maxn + 5];

void dfs(int x, int f = -1)
{
	dp[x][0] = mp(0, 0);
	REP(i, 1, m + 1) dp[x][i] = mp(0, -OO);

	sz[x] = 1;
	sum[x] = a[x];
	for (auto y : adj[x])
	{
		if (y != f)
		{
			dfs(y, x);
			for (int i = sz[x] - 1; i >= 0; --i) REP(j, 0, sz[y] + 1)
				chkmax(dp[x][i + j], mp(dp[x][i].x + dp[y][j].x, dp[x][i].y + dp[y][j].y));
			sz[x] += sz[y];
			sum[x] += sum[y];
		}
	}

	for (int i = m - 1; i >= 0; --i)
	{
		auto tmp = mp(dp[x][i].x + ((sum[x] + dp[x][i].y) > 0), -sum[x]);
		if (~f) chkmax(dp[x][i + 1], tmp); 
		else dp[x][i + 1] = tmp;
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		REP(i, 0, n)
		{
			int x;
			scanf("%d", &x);
			a[i] = -x;
		}
		REP(i, 0, n)
		{
			int x;
			scanf("%d", &x);
			a[i] = a[i] + x;
		}
		REP(i, 0, n) adj[i].clear();
		REP(i, 0, n - 1)
		{
			int u, v;
			scanf("%d%d", &u, &v), --u, --v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		dfs(0);
		printf("%d\n", dp[0][m].x);
	}
	return 0;
}