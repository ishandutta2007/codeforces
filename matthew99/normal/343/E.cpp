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

const int maxn = 200;

const int max0 = 200, max1 = 4000;

struct edge
{
	int id, g, nxt;
 
	edge() { }
	edge(int _id, int _g, int _nxt): id(_id), g(_g), nxt(_nxt) { }
 
};
 
int st[max0 + 5], en = 0;
edge e[max1 + 5];
 
inline void add_edge(int x, int y, int z)
{
	e[en] = edge(y, z, st[x]), st[x] = en++;
}
 
int n, m;
 
int S, T, N;

int dis[max0 + 5];
 
inline bool bfs()
{
	static int q[max0 + 5];
	static bool vis[max0 + 5];
	int head = 0, rear = 0;
	memset(dis, -1, sizeof(dis[0]) * N);
	memset(vis, 0, sizeof(vis[0]) * N);
	vis[q[rear++] = S] = 1;
	dis[S] = 0;
	while (head != rear)
	{
		int x = q[head++];
		for (int i = st[x]; i != -1; i = e[i].nxt)
		{
			if (!e[i].g) continue;
			int y = e[i].id;
			if (!vis[y])
			{
				dis[y] = dis[x] + 1;
				if (y == T) return 1;
				q[rear++] = y;
				vis[y] = 1;
			}
		}
	}
	return 0;
}
 
inline int dfs(int x, int flow)
{
	if (x == T) return flow;
	int res = flow;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		if (!e[i].g) continue;
		int y = e[i].id;
		if (dis[y] == dis[x] + 1)
		{
			int F = dfs(y, min(e[i].g, res));
			res -= F;
			e[i].g -= F;
			e[i ^ 1].g += F;
			if (res <= 0) return flow;
		}
	}
	dis[x] = -1;
	return flow - res;
}
 
int work()
{
	if (S == T) return oo;
	int ret = 0;
	for ( ; bfs(); ret += dfs(S, oo));
	return ret;
}

int f[maxn + 5][maxn + 5], g[maxn + 5][maxn + 5];

int ans;

void work(vector<int> &all)
{
	if (SZ(all) == 1) return;
	REP(i, 0, en >> 1)
	{
		int a = e[i << 1].g, b = e[i << 1 | 1].g;
		e[i << 1].g = (a + b) >>1, e[i << 1 | 1].g = (a + b) >> 1;
	}
	S = all[0], T = all[1];
	int tmp = work();
	ans += tmp;
	chkmin(f[S][T], tmp);
	chkmin(f[T][S], tmp);
	chkmin(g[S][T], tmp);
	chkmin(g[T][S], tmp);
	static bool vis[maxn + 5];
	memset(vis, 0, sizeof(vis[0]) * N);
	static int q[maxn + 5];
	int head = 0, rear = 0;
	q[rear++] = S;
	vis[S] = 1;
	while (head != rear)
	{
		int x = q[head++];
		for (int i = st[x]; i != -1; i = e[i].nxt)
		{
			if (!e[i].g) continue;
			int y = e[i].id;
			if (!vis[y]) q[rear++] = y, vis[y] = 1;
		}
	}
	vector<int> a, b;
	for (auto x : all) if (vis[x]) a.pb(x); else b.pb(x);
	all.clear();
	work(a), work(b);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(st, -1, sizeof st), en = 0;
	memset(f, oo, sizeof f);
	memset(g, oo, sizeof g);
	scanf("%d%d", &n, &m);
	REP(i, 0, n) g[i][i] = 0;
	N = n;
	REP(i, 0, m)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z), --x, --y;
		add_edge(x, y, z);
		add_edge(y, x, z);
	}
	vector<int> all;
	REP(i, 0, n) all.pb(i);
	work(all);
	REP(k, 0, n) REP(i, 0, n) REP(j, 0, n) chkmin(g[i][j], g[i][k] + g[k][j]);
	REP(i, 0, n) REP(j, 0, n) REP(k, 0, n) if (g[i][k] == g[i][j] + g[j][k]) chkmin(f[i][k], min(f[i][j], f[j][k]));
	printf("%d\n", ans);
	int cur = 0;
	static bool vis[maxn + 5];
	memset(vis, 0, sizeof vis);
	int ans0 = 0;
	REP(i, 0, n)
	{
		vis[cur] = 1;
		printf("%d ", cur + 1);
		if (i + 1 < n)
		{
			int Maxp = -1;
			REP(j, 0, n) if (!vis[j] && (Maxp == -1 || f[cur][j] > f[cur][Maxp])) Maxp = j;
			ans0 += f[cur][Maxp];
			cur = Maxp;
		}
	}
	assert(ans == ans0);
	return 0;
}