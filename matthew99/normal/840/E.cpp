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

const int maxn = 50010;

const int sz0 = 9, sz1 = 7;

int n, qn;
int a[maxn + 5];
vector<int> adj[maxn + 5];

int dep[maxn + 5];
int fa[maxn + 5];

int to[maxn + 5];

int seq[maxn + 5], seqn;

void dfs(int x)
{
	seq[seqn++] = x;
	for (auto y : adj[x])
		if (y != fa[x])
		{
			dep[y] = dep[x] + 1;
			fa[y] = x;
			dfs(y);
		}
}

int ans_small[maxn + 5][(1 << sz1) + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &qn);
	REP(i, 0, n) scanf("%d", a + i);
	REP(i, 0, n - 1)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].pb(v), adj[v].pb(u);
	}
	fa[0] = -1;
	seqn = 0;
	dep[0] = 0;
	dfs(0);
	REP(i, 0, n)
	{
		int u = i;
		static int Max[(1 << sz1) + 5];
		memset(Max, -1, sizeof Max);
		REP(j, 0, 1 << sz0)
		{
			if (!~u) break;
			chkmax(Max[(a[u] ^ j) >> sz0], (a[u] ^ j) & ((1 << sz0) - 1));
			u = fa[u];
		}
		to[i] = u;
		static bool vis[(1 << (sz1 + 1)) + 5];
		memset(vis, 0, sizeof vis);
		REP(j, 0, 1 << sz1) if (~Max[j])
			REP(k, 1, sz1 + 1)
				vis[j >> (sz1 - k) | (1 << k)] = 1;
		REP(j, 0, 1 << sz1)
		{
			int cur = 0;
			for (int k = sz1 - 1; k >= 0; --k)
			{
				if (vis[(1 << (sz1 - k)) | (cur << 1) | !(j >> k & 1)]) (cur <<= 1) |= !(j >> k & 1);
				else (cur <<= 1) |= (j >> k & 1);
			}
			ans_small[i][j] = ((j ^ cur) << sz0) | Max[cur];
		}
	}
	REP(i, 0, qn)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		int now = 0;
		int ans = 0;
		while (dep[v] - dep[u] >= (1 << sz0))
		{
			chkmax(ans, ans_small[v][now]);
			++now;
			v = to[v];
		}
		now <<= sz0;
		while (1)
		{
			chkmax(ans, a[v] ^ now);
			++now;
			if (u == v) break;
			v = fa[v];
		}
		printf("%d\n", ans);
	}
	return 0;
}