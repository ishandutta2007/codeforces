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

const int Mod = 1e9 + 7;

const int maxn = 100100, maxk = 210;

int n, K;
vector<int> adj[maxn + 5];

int S[maxk + 5][maxk + 5];
int fac[maxk + 5];

inline void prepare()
{
	REP(i, 0, maxk + 1)
	{
		S[i][0] = (i == 0);
		REP(j, 1, i + 1)
		{
			S[i][j] = (S[i - 1][j - 1] + (LL)j * S[i - 1][j]) % Mod;
		}
	}
	fac[0] = 1;
	REP(i, 0, maxk)
		fac[i + 1] = (LL)fac[i] * (i + 1) % Mod;
}

int sz[maxn + 5];
LL dp0[maxn + 5][maxk + 5];
LL dp1[maxn + 5][maxk + 5];

LL ans = 0;

void dfs(int x, int f = -1)
{
	dp1[x][0] = 1;
	sz[x] = 1;
	for (auto y : adj[x]) if (y != f)
	{
		dfs(y, x);
		static LL tmp0[maxk + 5];
		static LL tmp1[maxk + 5];
		memset(tmp0, 0, sizeof tmp0);
		memset(tmp1, 0, sizeof tmp1);
		REP(i, 0, min(K, sz[y]) + 1)
		{
			tmp0[i] = dp0[y][i];
			if (i > 0) (tmp0[i] += dp0[y][i - 1]) %= Mod;

			tmp1[i] = dp1[y][i];
			if (i > 0) (tmp1[i] += dp1[y][i - 1]) %= Mod;
		}
		static LL tmp2[maxk + 5];
		memset(tmp2, 0, sizeof tmp2);
		REP(i, 0, min(K, sz[x]) + 1) REP(j, 0, min(K - i, sz[y]) + 1)
			(tmp2[i + j] += (LL)(dp0[x][i] + dp1[x][i]) * (tmp0[j] + tmp1[j]) % Mod) %= Mod;
		REP(i, 0, K + 1) (dp1[x][i] += tmp2[i]) %= Mod;
		REP(i, 0, K + 1) (dp0[x][i] += (tmp0[i] + tmp1[i]) % Mod) %= Mod;
		sz[x] += sz[y];
	}
	REP(i, 0, K + 1)
		(ans += (LL)dp1[x][i] * fac[i] % Mod * S[K][i] % Mod) %= Mod;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	scanf("%d%d", &n, &K);
	REP(i, 0, n - 1)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0);
	(ans += Mod) %= Mod;
	printf("%lld\n", ans);
	return 0;
}