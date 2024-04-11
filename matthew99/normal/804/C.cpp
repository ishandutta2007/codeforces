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

const int maxn = 300100, maxm = 300100;

int n_v, n_t;

vector<int> adj[maxn + 5];
vector<int> all_type[maxn + 5];

int ans[maxm + 5];

void dfs(int x, int f = -1)
{
	set<int> ban;
	for (auto u : all_type[x])
		if (~ans[u]) ban.insert(ans[u]);
	int now = 0;
	for (auto u : all_type[x])
		if (!~ans[u])
		{
			while (ban.count(now)) ++now;
			ans[u] = now++;
		}
	for (auto y : adj[x]) if (y != f)
	{
		dfs(y, x);
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n_v, &n_t);
	int Max = 1;
	REP(i, 0, n_v)
	{
		int m;
		scanf("%d", &m);
		chkmax(Max, m);
		REP(j, 0, m)
		{
			int x;
			scanf("%d", &x), --x;
			all_type[i].pb(x);
		}
	}
	REP(i, 0, n_v - 1)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	memset(ans, -1, sizeof ans);
	dfs(0);
	printf("%d\n", Max);
	REP(i, 0, n_t)
	{
		if (!~ans[i]) ans[i] = 0;
		printf("%d ", ans[i] + 1);
	}
	return 0;
}