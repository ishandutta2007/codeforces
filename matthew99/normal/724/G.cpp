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

const int maxn = 100010, maxm = 200010;

vector<pair<int, LL> > adj[maxn + 5];

int ans;

int n, m;
int fa[maxn + 5];

vector<pair<pair<int, int>, LL> > spare;

inline int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }

LL sum[maxn + 5];

vector<int> seq;
vector<int> all[maxn + 5];

void dfs(int x, int f = -1)
{
	seq.pb(x);
	for (auto y : adj[x]) if (y.x != f)
	{
		sum[y.x] = sum[x] ^ y.y;
		dfs(y.x, x);
	}
}

int pw2[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	pw2[0] = 1;
	REP(i, 0, maxn) (pw2[i + 1] = pw2[i] << 1) %= Mod;
	scanf("%d%d", &n, &m);
	REP(i, 0, n) fa[i] = i;
	REP(i, 0, m)
	{
		int u, v;
		LL w;
		scanf("%d%d%I64d", &u, &v, &w), --u, --v;
		if (get(u) != get(v)) fa[get(u)] = get(v), adj[u].pb(mp(v, w)), adj[v].pb(mp(u, w));
		else spare.pb(mp(mp(u, v), w));
	}
	REP(i, 0, SZ(spare)) all[get(spare[i].x.x)].pb(i);
	ans = 0;
	REP(i, 0, n) if (fa[i] == i)
	{
		seq.clear();
		sum[i] = 0;
		dfs(i);
		static bool has[100];
		memset(has, 0, sizeof has);
		int cnt = 0;
		static LL base[100];
		memset(base, -1, sizeof base);
		for (auto u : all[i])
		{
			LL tmp = sum[spare[u].x.x] ^ sum[spare[u].x.y] ^ spare[u].y;
			if (!tmp) continue;
			REP(j, 0, 60) has[j] |= tmp >> j & 1;
			REP(j, 0, 60) if (tmp >> j & 1)
			{
				if (!~base[j]) { ++cnt, base[j] = tmp; break; }
				else tmp ^= base[j];
			}
		}
		int tot = 0;
		REP(j, 0, 60) 
			if (!has[j])
			{
				int num = 0;
				for (auto u : seq) if (sum[u] >> j & 1) ++num;
				(tot += (LL)num * (SZ(seq) - num) % Mod * pw2[j] % Mod) %= Mod;
			}
			else (tot += (LL)SZ(seq) * (SZ(seq) - 1) % Mod * ((Mod + 1) >> 2) % Mod * pw2[j] % Mod) %= Mod;
		(ans += (LL)tot * pw2[cnt] % Mod) %= Mod;
	}
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}