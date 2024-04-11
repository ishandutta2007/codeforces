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

const int maxn = 1000, maxm = 12;

int n, m;
vector<int> adj[maxn + 5], adjf[maxm + 5];

map<int, vector<int> > way;

inline int blen(int x) { return 32 - __builtin_clz(x); }

inline int combine(int x, int y) { return x << blen(y) | y; }

int dfsf(int x, int f = -1)
{
	vector<int> s;
	for (auto y : adjf[x]) if (y != f) s.pb(dfsf(y, x));
	sort(ALL(s));
	int ret = 1;
	for (auto u : s) ret = combine(ret, u);
	ret <<= 1;
	if (!way.count(ret)) way[ret] = s;
	return ret;
}

int ans;

map<int, int> dp[maxn + 5];

void dfs(int x, int f = -1)
{
	vector<int> chd;
	for (auto y : adj[x]) if (y != f)
	{
		chd.pb(y);
		dfs(y, x);
	}
	for (const auto &u : way)
	{
		auto &v = u.y;
		int N = SZ(u.y);
		static int pd[(1 << maxm) + 5];
		memset(pd, 0, sizeof(pd[0]) * (1 << N));
		pd[0] = 1;
		for (auto y : chd)
		{
			static int nxt[(1 << maxm) + 5];
			memcpy(nxt, pd, sizeof(nxt[0]) * (1 << N));
			REP(i, 0, N) 
			{
				int num = dp[y][v[i]];
				if (!num) continue;
				for (int j = (1 << N) - 1; j >= 0; --j) if (pd[j] && !(j >> i & 1) && !(i && v[i] == v[i - 1] && !(j >> (i - 1) & 1)))
					(nxt[j | (1 << i)] += (LL)pd[j] * num % Mod) %= Mod;
			}
			memcpy(pd, nxt, sizeof(pd[0]) * (1 << N));
		}
		if (pd[(1 << N) - 1]) 
		{
			dp[x][u.x] = pd[(1 << N) - 1];
			if (blen(u.x) == (m << 1)) (ans += pd[(1 << N) - 1]) %= Mod;
		}
	}
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
		adj[u].pb(v), adj[v].pb(u);
	}
	scanf("%d", &m);
	REP(i, 0, m - 1)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adjf[u].pb(v), adjf[v].pb(u);
	}
	REP(i, 0, m) dfsf(i);
	ans = 0;
	dfs(0);
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}