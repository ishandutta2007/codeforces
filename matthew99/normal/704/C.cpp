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

const int maxn = 100100, maxm = 100100;

int kind[(maxm << 1) + 5];
vector<pair<int, int> > adj[maxn + 5];

int deg[maxn + 5];

bool vis[maxn + 5];

bool ty[maxn + 5][2];

int num[2];

int need = 1;

int n, m;

inline void deal(int i)
{
	static int nxt_num[2];
	memset(nxt_num, 0, sizeof nxt_num);
	REP(j, 0, 2)
	{
		static int dp[2][2];
		memset(dp, 0, sizeof dp);
		int what = 0;
		if (ty[i][0]) what ^= j;
		if (ty[i][1]) what ^= !j;
		dp[j][what] = 1;
		int u = i;
		int lste = -1;
		while (1)
		{
			vis[u] = 1;
			int nxt = -1;
			int nxt_kind = -1;
			for (auto v : adj[u])
			{
				if ((v.y ^ 1) != lste)
				{
					nxt = v.x;
					nxt_kind = kind[v.y];
					lste = v.y;
					break;
				}
			}
			if (!~nxt) break;
			u = nxt;
			static int nxt_dp[2][2];
			memset(nxt_dp, 0, sizeof nxt_dp);
			REP(k, 0, 2)
			{
				int tmp = 0;
				if (u == i) 
				{
					tmp = 0;
					if (k != j) continue;
				}
				else
				{
					if (ty[u][0]) tmp ^= k;
					if (ty[u][1]) tmp ^= !k;
				}
				REP(lst, 0, 2) REP(val, 0, 2) if (dp[lst][val])
				{
					int nxt_val = val ^ tmp;
					what = 0;
					if (nxt_kind & 1) what |= !lst;
					else what |= lst;
					if (nxt_kind & 2) what |= !k;
					else what |= k;
					nxt_val ^= what;
					(nxt_dp[k][nxt_val] += dp[lst][val]) %= Mod;
				}
			}
			memcpy(dp, nxt_dp, sizeof dp);
			if (u == i) break;
		}
		REP(k, 0, 2) REP(a, 0, 2) REP(b, 0, 2) (nxt_num[b ^ k] += (LL)num[k] * dp[a][b] % Mod) %= Mod;
	}
	memcpy(num, nxt_num, sizeof num);
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &m, &n);
	REP(i, 0, m)
	{
		int K, x, y;
		scanf("%d", &K);
		if (K == 1)
		{
			scanf("%d", &x);
			if (x > 0) ty[(x - 1)][0] ^= 1;
			else x = -x, ty[(x - 1)][1] ^= 1;
		}
		else
		{
			scanf("%d%d", &x, &y);
			if (x == y)
			{
				if (x > 0) ty[(x - 1)][0] ^= 1;
				else x = -x, ty[(x - 1)][1] ^= 1;
			}
			else if (x == -y) need ^= 1;
			else
			{
				kind[i << 1] = kind[i << 1 | 1] = 0;
				if (x < 0) x = -x, kind[i << 1] |= 1, kind[i << 1 | 1] |= 2;
				if (y < 0) y = -y, kind[i << 1] |= 2, kind[i << 1 | 1] |= 1;
				--x, --y;
				adj[x].pb(mp(y, i << 1));
				adj[y].pb(mp(x, i << 1 | 1));
				++deg[x], ++deg[y];
			}
		}
	}
	num[0] = 1;
	REP(i, 0, n) if (!vis[i] && deg[i] == 1) deal(i);
	REP(i, 0, n) if (!vis[i]) deal(i);
	int ans = num[need];
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}