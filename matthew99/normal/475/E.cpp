#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) ({})//fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

const int oo = 0x3f3f3f3f;

typedef long long LL;

const int maxn = 2000;

int n, m;

vector<int> e[maxn + 5];

void init()
{
	scanf("%d%d", &n, &m);
	REP(i, 0, m)
	{
		static int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		e[x].pb(y), e[y].pb(x);
	}
}

int pre[maxn + 5], dfs_clock = 0;

bool f[maxn + 5][maxn + 5] = {{0}};

int dfs(const int &u, const int &fa = -1)
{
	int lowu = pre[u] = dfs_clock++;
	REP(i, 0, SZ(e[u]))
	{
		const int &v = e[u][i];
		if (pre[v] == -1)
		{
			int lowv = dfs(v, u);
			lowu = min(lowu, lowv);
			if (lowv > pre[u]) f[u][v] = f[v][u] = 1;
		}
		else if (pre[v] < pre[u] && v != fa) lowu = min(lowu, pre[v]);
	}
	return lowu;
}

bool vis[maxn + 5] = {0};

int col = 0;

int bccno[maxn + 5];

int ans = 0;

int lyc = 0;

void dfs0(const int &x)
{
	++lyc;
	vis[x] = 1;
	bccno[x] = col;
	REP(i, 0, SZ(e[x]))
	{
		const int &y = e[x][i];
		if (f[x][y]) continue;
		if (!vis[y]) dfs0(y);
	}
}

vector<int> T[maxn + 5];

int w[maxn + 5];

bool dp[maxn + 5][maxn + 5] = {{0}};

int sz[maxn + 5];

int tot[maxn + 5];

int nofst = 0;

void dfs1(const int &x, const int &f = -1)
{
	sz[x] = w[x];
	tot[x] = 0;
	dp[x][0] = 1;
	int cnt = 0;
	REP(i, 0, SZ(T[x]))
	{
		const int &y = T[x][i];
		if (y == f) continue;
		dfs1(y, x);
		sz[x] += sz[y];
		tot[x] += tot[y] + sz[y] * w[x];
		cnt += tot[y];
		if (f == -1)
			for (int j = n; j >= 0; --j)
				if (dp[x][j]) dp[x][j + sz[y]] = 1;
	}
	if (f == -1)
	{
		REP(i, 0, n)
			if (dp[x][i]) debug("%d %d: %d %d\n", x, i, i * (n - i) + w[x] * (n - i - w[x]), cnt), nofst = max(nofst, i * (n - i) + w[x] * (n - i - w[x]) + cnt);
	}
}

void solve()
{
	memset(vis, 0, sizeof vis);
	REP(i, 0, n)
		if (!vis[i]) lyc = 0, dfs0(i), w[col] = lyc, ans += lyc * lyc, ++col;
	REP(i, 0, n) debug("%d ", bccno[i]);
	debug("\n");
	REP(i, 0, n)
		REP(j, 0, n)
			if (f[i][j]) debug("%d %d\n", bccno[i], bccno[j]), T[bccno[i]].pb(bccno[j]);
	debug("\n");
	memset(dp, 0, sizeof dp);
	REP(i, 0, n) dfs1(i);
	debug("%d\n", ans);
	debug("%d\n", nofst);
	ans += nofst;
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
	memset(pre, -1, sizeof pre);
	dfs(0);
	solve();
	output();
	return 0;
}