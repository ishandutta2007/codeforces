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

const int maxn = 1000100;

int n, m, K;
vector<int> adj[maxn + 5];

int dfs_tot = 0;
int seq[maxn + 5];

bool vis[maxn + 5];

void dfs(int x)
{
	seq[dfs_tot++] = x;
	vis[x] = 1;
	for (auto y : adj[x]) if (!vis[y])
	{
		dfs(y);
		seq[dfs_tot++] = x;
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &K);
	REP(i, 0, m)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	memset(vis, 0, sizeof vis);
	dfs_tot = 0;
	dfs(0);
	int now = 0;
	REP(i, 0, K)
	{
		int num = (dfs_tot - now) / (K - i);
		printf("%d", num);
		REP(j, 0, num) printf(" %d", seq[now++] + 1);
		printf("\n");
	}
	return 0;
}