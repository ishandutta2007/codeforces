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
const int maxcnt = 10;

const int Mod = 1e9 + 7;

int n, m;
vector<int> adj[maxn + 5];

int K, cnt;

int dp[maxn + 5][maxcnt + 5][3];

void dfs(int x, int f = -1)
{
	dp[x][0][0] = K - 1;
	dp[x][1][1] = 1;
	dp[x][0][2] = m - K;
	for (auto y : adj[x]) if (y != f)
	{
		dfs(y, x);
		static int nxt[maxcnt + 5][3];
		memset(nxt, 0, sizeof nxt);
		REP(i, 0, cnt + 1) REP(j, 0, 3) if (dp[x][i][j])
			REP(k, 0, cnt - i + 1) REP(l, 0, 3) if (dp[y][k][l])
			{
				if ((j == 1 && l >= 1) || (l == 1 && j >= 1)) continue;
				(nxt[i + k][j] += (LL)dp[x][i][j] * dp[y][k][l] % Mod) %= Mod;
			}
		memcpy(dp[x], nxt, sizeof dp[x]);
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n - 1)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	scanf("%d%d", &K, &cnt);
	dfs(0);
	int ans = 0;
	REP(i, 0, cnt + 1)
		REP(j, 0, 3) (ans += dp[0][i][j]) %= Mod;
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}