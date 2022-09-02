#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
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

const int maxn = 10100, maxk = 5, maxway = 210;
const int maxbit = 6, bitlen = 3, bitval = (1 << bitlen) - 1;

typedef bitset<maxn + 5> Int;

int numtr[maxk + 5];

int n, K;

int N = 0;
vector<int> S[maxn + 5];
vector<int> adj[maxn + 5];
bitset<maxn + 5> wh[maxn + 5];

int id[1 << (bitlen * maxbit)];
int num_set[maxway + 5];
int what[maxway + 5];
int tot = 0;

int tr[maxway + 5][maxway + 5];

int sz[maxk + 5];

void get_par(int x, int y, int val = 0)
{
	if (x == K + 1)
	{
		num_set[tot] = y;
		what[id[val] = tot++] = val;
		return;
	}
	REP(i, 0, y + 1) 
	{
		++sz[i];
		get_par(x + 1, max(y, i + 1), val | (i << (x * bitlen)));
		--sz[i];
	}
}

namespace DSU
{
	int fa[maxk + 5];

	int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }

	int get_id()
	{
		static int M[maxk + 5];
		memset(M, -1, sizeof M);
		int Mtot = 0;
		int ret = 0;
		REP(i, 0, K + 1)
		{
			int u = get(i);
			if (!~M[u]) M[u] = Mtot++;
			ret |= M[u] << (i * bitlen);
		}
		return id[ret];
	}
}

inline void get_tr()
{
	REP(i, 0, tot) REP(j, 0, i + 1)
	{
		static int a[maxk + 5], b[maxk + 5];
		int u = what[i], v = what[j];
		REP(k, 0, K + 1) a[k] = u & bitval, u >>= bitlen, b[k] = v & bitval, v >>= bitlen;
		using namespace DSU;
		REP(k, 0, K + 1) fa[k] = k;
		REP(k, 0, K + 1) REP(l, 0, k) if (a[k] == a[l] || b[k] == b[l]) { fa[get(k)] = get(l); }
		int tmp = get_id();
		if ((K + 1 - num_set[i]) + (K + 1 - num_set[j]) != K + 1 - num_set[tmp]) { tr[i][j] = tr[j][i] = -1; continue; }
		tr[i][j] = tr[j][i] = tmp;
	}
}

int dp[maxn + 5][maxway + 5];

int ide[maxk + 5][maxk + 5];

void dfs(int x, int f = -1)
{
	static bool both[maxk + 5];
	memset(both, 0, sizeof both);
	if (~f) REP(i, 0, K + 1) both[i] = count(ALL(S[f]), S[x][i]);
	int mask = (1 << (K * (K + 1) >> 1)) - 1;
	REP(i, 0, K + 1) if (both[i]) REP(j, 0, i) if (both[j]) mask ^= 1 << ide[i][j];
	memset(dp[x], 0, sizeof dp[x]);
	for (int i = mask; ; i = (i - 1) & mask)
	{
		using namespace DSU;
		REP(j, 0, K + 1) fa[j] = j;
		bool failed = 0;
		REP(j, 0, K + 1) if (!failed) REP(k, 0, j) 
			if (i >> ide[j][k] & 1)
			{
				if (get(j) == get(k)) { failed = 1; break; }
				fa[get(j)] = get(k);
			}
		if (!failed) ++dp[x][get_id()];
		if (!i) break;
	}
	for (auto y : adj[x]) 
	{
		dfs(y, x);
		static int idx[maxk + 5], idy[maxk + 5];
		REP(i, 0, K + 1)
		{
			idx[i] = idy[i] = -1;
			REP(j, 0, K + 1) 
			{
				if (S[y][i] == S[x][j]) idy[i] = j;
				if (S[x][i] == S[y][j]) idx[i] = j;
			}
		}
		static int sum[maxway + 5];
		memset(sum, 0, sizeof sum);
		static int a[maxk + 5];
		REP(i, 0, tot) if (dp[y][i])
		{
			int u = what[i];
			REP(j, 0, K + 1) a[j] = u & bitval, u >>= bitlen;
			bool failed = 0;
			REP(j, 0, K + 1) 
				if (!~idy[j]) 
				{
					bool find = 0;
					REP(k, 0, K + 1) if (~idy[k] && a[j] == a[k]) { find = 1; break; }
					if (!find) { failed = 1; break; }
				}
			if (failed) continue;
			using namespace DSU;
			REP(j, 0, K + 1) fa[j] = j;
			REP(j, 0, K + 1) if (~idx[j]) REP(k, 0, j) if (~idx[k]) if (a[idx[j]] == a[idx[k]]) fa[get(j)] = get(k);
			(sum[get_id()] += dp[y][i]) %= Mod;
		}
		static int nxt[maxway + 5];
		memset(nxt, 0, sizeof nxt);
		REP(i, 0, tot) if (sum[i]) REP(j, 0, tot) if (dp[x][j] && ~tr[i][j]) (nxt[tr[i][j]] += (LL)sum[i] * dp[x][j] % Mod) %= Mod;
		memcpy(dp[x], nxt, sizeof dp[x]);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	int idetot = 0;
	REP(i, 0, K + 1) REP(j, 0, i) ide[i][j] = idetot++;
	REP(i, 0, maxk + 3) if (i <= 2) numtr[i] = 1; else numtr[i] = fpm(i, i - 2, Mod);
	if (n == K)
	{
		printf("%d\n", numtr[n]);
		return 0;
	}
	REP(i, 0, K + 1) S[0].pb(i), wh[i][0] = 1;
	N++;
	REP(i, K, n)
	{
		if (i == K) { REP(j, 0, K) scanf("%*d"); continue; }
		int x;
		Int tmp;
		tmp = ~tmp;
		S[N].clear();
		S[N].pb(i);
		wh[i][N] = 1;
		REP(j, 0, K)
		{
			scanf("%d", &x), --x;
			tmp &= wh[x];
			wh[x][N] = 1;
			S[N].pb(x);
		}
		int id = tmp._Find_next(-1);
		assert(id < N); 
		adj[id].pb(N);
		++N;
	}
	memset(id, -1, sizeof id);
	memset(sz, 0, sizeof sz);
	get_par(0, 0);
	get_tr();
	dfs(0);
	int ans = dp[0][0];
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}