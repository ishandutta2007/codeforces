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

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 200100, maxm = 200100;

int n, m, K;

pair<int, int> e[maxn + 5];
vector<int> adj[maxn + 5];

bool vis[maxn + 5];
int deg[maxn + 5];

bool in[maxn + 5];

int cur;
queue<int> q;

int ans[maxm + 5];

inline void clear()
{
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		if (!in[u]) continue;
		in[u] = 0;
		--cur;
		for (auto v : adj[u]) if (in[v])
		{
			--deg[v];
			if (deg[v] < K) q.push(v);
		}
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
		e[i] = mp(u, v);
		++deg[u], ++deg[v];
	}
	REP(i, 0, n) in[i] = 1;
	cur = n;
	REP(i, 0, n) if (deg[i] < K) q.push(i);
	clear();
	for (int i = m - 1; i >= 0; --i)
	{
		ans[i] = cur;
		adj[e[i].x].pop_back();
		adj[e[i].y].pop_back();
		if (in[e[i].x] && in[e[i].y]) 
		{
			--deg[e[i].x], --deg[e[i].y];
			if (deg[e[i].x] < K) q.push(e[i].x);
			if (deg[e[i].y] < K) q.push(e[i].y);
		}
		clear();
	}
	REP(i, 0, m) printf("%d\n", ans[i]);
	return 0;
}