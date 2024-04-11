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

const int maxn = 500100;

LL dp[maxn + 5][2];

int n, K;
vector<pair<int, int> > adj[maxn + 5];

void dfs(int x, int f = -1)
{
	vector<LL> all;
	dp[x][0] = dp[x][1] = 0;
	for (auto y : adj[x])
		if (y.x != f)
		{
			dfs(y.x, x);
			dp[x][0] += dp[y.x][0];
			dp[x][1] += dp[y.x][0];
			all.pb(dp[y.x][1] + y.y - dp[y.x][0]);
		}
	sort(ALL(all), greater<LL>());
	REP(i, 0, min(SZ(all), K)) dp[x][0] += max(0LL, all[i]);
	REP(i, 0, min(SZ(all), K - 1)) dp[x][1] += max(0LL, all[i]);
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
		scanf("%d%d", &n, &K);
		REP(i, 0, n) adj[i].clear();
		REP(i, 0, n - 1)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w), --u, --v;
			adj[u].pb(mp(v, w));
			adj[v].pb(mp(u, w));
		}
		dfs(0);
		printf("%lld\n", dp[0][0]);
	}
	return 0;
}