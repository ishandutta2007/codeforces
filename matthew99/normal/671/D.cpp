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

const int maxn = 300000;

int n, m;
vector<int> adj[maxn + 5];

int dep[maxn + 5], fa[maxn + 5];

void pre_dfs(int x) { for (auto y : adj[x]) { if (y == fa[x]) continue; fa[y] = x, dep[y] = dep[x] + 1, pre_dfs(y); } }

set<pair<int, int> > all[maxn + 5];
int delta[maxn + 5];

LL ans = 0;

inline void merge(int u, int v)
{
	if (SZ(all[u]) > SZ(all[v])) swap(all[u], all[v]), swap(delta[u], delta[v]);
	int d = delta[u] - delta[v];
	for (auto x : all[u]) all[v].insert(mp(x.x + d, x.y));
	all[u].clear();
}

int dfs(int x)
{
	int id = x;
	for (auto y : adj[x]) if (y != fa[x])
	{
		int tmp = dfs(y);
		if (dep[tmp] < dep[id]) id = tmp;
	}
	if (x == 0) return x;
	if (id == x)
	{
		while (!all[x].empty() && dep[all[x].begin()->y] >= dep[x]) all[x].erase(all[x].begin());
		if (all[x].empty()) { puts("-1"); exit(0); }
		auto cur = *all[x].begin();
		all[x].erase(all[x].begin());
		ans += delta[x] + cur.x;
		delta[x] = -cur.x;
		merge(x, cur.y);
		id = cur.y;
	}
	else merge(x, id);
	return id;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n - 1)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	fa[0] = -1;
	pre_dfs(0);
	REP(i, 0, m)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w), --u, --v;
		if (u != v) all[u].insert(mp(w, v));
	}
	dfs(0);
	printf("%I64d\n", ans);
	return 0;
}