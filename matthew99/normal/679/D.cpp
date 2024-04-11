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

const int maxn = 400;

int n, m;
vector<int> adj[maxn + 5];

int dis[maxn + 5][maxn + 5];

double ans;

inline void bfs(int x, int *dis)
{
	static bool vis[maxn + 5];
	memset(vis, 0, sizeof vis);
	queue<int> q; q.push(x), vis[x] = 1, dis[x] = 0;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (auto v : adj[u]) if (!vis[v]) vis[v] = 1, q.push(v), dis[v] = dis[u] + 1;
	}
}

double inv[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 1, n + 1) inv[i] = 1. / i;
	REP(i, 0, m)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].pb(v), adj[v].pb(u);
	}
	REP(i, 0, n) bfs(i, dis[i]);
	ans = 0;
	REP(i, 0, n)
	{
		double tmp = 0;
		REP(j, 0, n)
		{
			static double sum[maxn + 5];
			static bool vis[maxn + 5];
			memset(sum, 0, sizeof sum);
			memset(vis, 0, sizeof vis);
			int cnt = 0;
			REP(k, 0, n) if (dis[i][k] == j) 
			{
				double per = inv[SZ(adj[k])];
				for (auto l : adj[k]) sum[l] += per, vis[l] = 1;
				++cnt;
			}
			if (!cnt) continue;
			vector<int> all;
			REP(k, 0, n) if (vis[k]) all.pb(k);
			double ret = 1; 
			static int num[maxn + 5];
			static double Max[maxn + 5];
			REP(k, 0, n)
			{
				for (auto tmp : all) num[dis[k][tmp]] = 0, Max[dis[k][tmp]] = 0;
				for (auto tmp : all) ++num[dis[k][tmp]], chkmax(Max[dis[k][tmp]], sum[tmp]);
				double foo = 0;
				for (auto tmp : all) foo += Max[dis[k][tmp]], Max[dis[k][tmp]] = 0;
				chkmax(ret, foo);
			}
			tmp += ret;
		}
		chkmax(ans, tmp);
	}
	ans *= inv[n];
	printf("%.15f\n", ans);
	return 0;
}