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

const int maxn = 60;

const int max_ans = 1e7;

int n;
int dp[maxn + 5][maxn + 5];

vector<pair<int, int> > adj[maxn + 5];

int f[maxn + 5][maxn + 5];

bool leaf[maxn + 5];

int s, m;

int cri[maxn + 5];

inline bool check0(int ccnt, int rt, int lim)
{
	int ret = 0;
	REP(i, 0, n) if (i != rt && leaf[i])
	{
		if (f[rt][i] > lim) return 0;
		int k = 0;
		while (k < ccnt && dp[ccnt - k - 1][i] + f[rt][i] > lim) ++k;
		ret += k;
	}
	return ret < ccnt;
}

inline bool check1(int ccnt, vector<int> leaves, int lim)
{
	int ret = 0;
	for (auto i : leaves)
	{
		if (f[s][i] > lim) return 0;
		int k = 0;
		while (k < m && dp[m - k - 1][i] + f[s][i] > lim) ++k;
		ret += k;
	}
	return ret < ccnt;
}

int tot_cri[maxn + 5];
vector<int> leaves[maxn + 5];

int fa[maxn + 5];

void dfs(int x)
{
	for (auto y : adj[x]) if (y.x != fa[x]) fa[y.x] = x, dfs(y.x);
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	memset(f, oo, sizeof f);
	REP(i, 0, n) f[i][i] = 0;
	REP(i, 0, n - 1)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w), --u, --v;
		f[u][v] = f[v][u] = w;
		adj[u].pb(mp(v, w));
		adj[v].pb(mp(u, w));
	}
	scanf("%d%d", &s, &m);
	--s;
	REP(i, 0, m)
	{
		int x;
		scanf("%d", &x), --x;
		if (x == s) --m;
		else ++cri[x];
	}
	REP(k, 0, n) REP(i, 0, n) REP(j, 0, n) chkmin(f[i][j], f[i][k] + f[k][j]);
	REP(i, 0, n) leaf[i] = SZ(adj[i]) == 1;
	REP(i, 0, n) if (leaf[i]) dp[0][i] = 0;
	REP(i, 1, m + 1)
	{
		REP(j, 0, n) if (leaf[j])
		{
			int l = 0, r = max_ans; 
			while (l < r)
			{
				int mid = (l + r) >> 1;
				if (check0(i, j, mid)) r = mid;
				else l = mid + 1;
			}
			dp[i][j] = l;
		}
	}
	fa[s] = -1;
	dfs(s);
	REP(i, 0, n) if (i != s)
	{
		int u = i;
		while (fa[u] != s) u = fa[u];
		tot_cri[u] += cri[i];
		if (leaf[i]) leaves[u].pb(i);
	}
	int ans = max_ans;
	for (auto u : adj[s])
	{
		int x = u.x;
		int l = 0, r = max_ans;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (check1(tot_cri[x], leaves[x], mid)) r = mid;
			else l = mid + 1;
		}
		chkmin(ans, l);
	}
	printf("%d\n", ans);
	return 0;
}