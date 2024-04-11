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

const int Mod = 998244353;

const int maxn = 200100;

int dp0[maxn + 5], dp1[maxn + 5], dp2[maxn + 5];

int n;
vector<int> adj[maxn + 5];

void dfs(int x, int f = -1)
{
	dp0[x] = dp1[x] = dp2[x] = 0;
	bool flag = 0;
	int tmp = 1;
	for (auto y : adj[x])
	{
		if (y != f)
		{
			dfs(y, x);
			dp0[x] = (LL)dp0[x] * dp2[y] % Mod;
			dp1[x] = (LL)dp1[x] * dp2[y] % Mod;
			dp2[x] = (LL)dp2[x] * dp2[y] % Mod;
			(dp2[x] += (LL)tmp * dp0[y] % Mod) %= Mod;
			if (flag)
			{
				(dp0[x] += (LL)tmp * dp0[y] % Mod) %= Mod;
			}
			else
			{
				(dp1[x] += (LL)tmp * dp0[y] % Mod) %= Mod;
			}
			tmp = (LL)tmp * dp1[y] % Mod;
		}
		else (dp1[x] += tmp) %= Mod, flag = 1;
	}
	(dp0[x] += tmp) %= Mod;
	(dp2[x] += tmp) %= Mod;
}

int main()
{
#ifdef matthew99
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
	dfs(0);
	(dp2[0] += Mod) %= Mod;
	printf("%d\n", dp2[0]);
	return 0;
}