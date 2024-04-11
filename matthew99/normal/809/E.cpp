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

const int Mod = 1e9 + 7;

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

const int maxn = 200100;

int n;
int a[maxn + 5];

int ans;

vector<int> adj[maxn + 5];

int mu[maxn + 5];
int phi[maxn + 5];

int val[maxn + 5];

vector<int> fac[maxn + 5];

inline void prepare()
{
	memset(mu, 0, sizeof mu);
	mu[1] = 1;
	for (int i = 1; i <= maxn; ++i)
		for (int j = (i << 1); j <= maxn; j += i)
			mu[j] -= mu[i];
	for (int i = 1; i <= maxn; ++i)
		for (int j = 1; i * j <= maxn; ++j)
			phi[i * j] += mu[i] * j;
	static int tmp[maxn + 5];
	REP(i, 1, maxn + 1) tmp[i] = (LL)i * fpm(phi[i], Mod - 2, Mod) % Mod;
	for (int i = 1; i <= maxn; ++i)
		for (int j = 1; i * j <= maxn; ++j)
			(val[i * j] += (LL)mu[i] * tmp[j] % Mod) %= Mod;
	for (int i = 1; i <= maxn; ++i)
		for (int j = i; j <= maxn; j += i)
			fac[j].pb(i);
}

int sz[maxn + 5];
int Max[maxn + 5];
int dfs_seq[maxn + 5], dfs_tot = 0;

bool del[maxn + 5];

void pre_dfs(int x, int f = -1)
{
	dfs_seq[dfs_tot++] = x;
	sz[x] = 1;
	Max[x] = 0;
	for (auto y : adj[x]) if (!del[y])
	{
		if (y == f) continue;
		pre_dfs(y, x);
		sz[x] += sz[y];
		chkmax(Max[x], sz[y]);
	}
}

int sum[maxn + 5], sumd[maxn + 5];

int dep[maxn + 5];

vector<int> chd;

void formal_dfs(int x, int d = 0, int f = -1)
{
	dep[x] = d;
	if (~f) 
	{
		chd.pb(x);
		for (auto u : fac[a[x]]) 
		{
			(ans += (LL)phi[a[x]] * d % Mod * sum[u] % Mod * val[u] % Mod) %= Mod;
			(ans += (LL)phi[a[x]] * sumd[u] % Mod * val[u] % Mod) %= Mod;
		}
	}
	else
	{
		for (auto u : fac[a[x]]) (sum[u] += phi[a[x]]) %= Mod;
	}
	sz[x] = 1;
	Max[x] = 0;
	for (auto y : adj[x]) if (!del[y])
	{
		if (y == f) continue;
		formal_dfs(y, d + 1, x);
		if (!~f)
		{
			for (auto u : chd)
			{
				for (auto v : fac[a[u]])
				{
					(sum[v] += phi[a[u]]) %= Mod;
					(sumd[v] += (LL)phi[a[u]] * dep[u] % Mod) %= Mod;
				}
			}
			chd.clear();
		}
	}
}

void work(int rt)
{
	dfs_tot = 0;
	pre_dfs(rt);
	int x = -1;
	REP(i, 0, dfs_tot)
	{
		int y = dfs_seq[i];
		for (auto u : fac[a[y]]) sum[u] = sumd[u] = 0;
		chkmax(Max[y], sz[rt] - sz[y]);
		if (x == -1 || Max[y] < Max[x]) x = y;
	}
	chd.clear();
	formal_dfs(x);
	del[x] = 1;
	for (auto y : adj[x]) if (!del[y]) work(y);
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	REP(i, 0, n) adj[i].clear();
	REP(i, 0, n - 1)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	work(0);
	(ans <<= 1) %= Mod;
	ans = (LL)ans * fpm((LL)n * (n - 1) % Mod, Mod - 2, Mod) % Mod;
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}