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

const int maxn = 100100, maxk = 110;

int n, m, K, s;
vector<int> adj[maxn + 5];
vector<int> all[maxk + 5];

int dis[maxn + 5][maxk + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d%d", &n, &m, &K, &s);
	REP(i, 0, n)
	{
		int x;
		scanf("%d", &x), --x;
		all[x].pb(i);
	}
	REP(i, 0, m)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].pb(v), adj[v].pb(u);
	}
	REP(i, 0, K)
	{
		queue<int> q;
		REP(j, 0, n) dis[j][i] = oo;
		for (auto x : all[i]) q.push(x), dis[x][i] = 0;
		while (!q.empty())
		{
			int x = q.front(); q.pop();
			for (auto y : adj[x]) if (chkmin(dis[y][i], dis[x][i] + 1)) q.push(y);
		}
	}
	REP(i, 0, n)
	{
		int ans = 0;
		nth_element(dis[i], dis[i] + s - 1, dis[i] + K);
		REP(j, 0, s) ans += dis[i][j];
		printf("%d\n", ans);
	}
	return 0;
}