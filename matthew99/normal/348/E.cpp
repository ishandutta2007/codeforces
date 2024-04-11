#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int((x).size()))
#define pb push_back

using namespace std;

const int maxn = 100000;

int n, m;

vector<pair<int, int> > e[maxn + 5];

bool black[maxn + 5] = {0};

int d[maxn + 5] = {0};

bool kill[maxn + 5] = {0};

void init()
{
	scanf("%d%d", &n, &m);
	REP(i, 0, m)
	{
		static int x;
		scanf("%d", &x), black[--x] = 1;
	}
	REP(i, 0, n - 1)
	{
		static int x, y, z;
		scanf("%d%d%d", &x, &y, &z), --x, --y;
		e[x].pb(mp(y, z)), e[y].pb(mp(x, z));
		++d[x], ++d[y];
	}
}

void prepare()
{
	queue<int> q;
	REP(i, 0, n) if (d[i] == 1 && !black[i]) q.push(i);
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		kill[x] = 1;
		REP(i, 0, SZ(e[x]))
		{
			const int &y = e[x][i].x;
			if (--d[y] == 1 && !black[y]) q.push(y);
		}
	}
	REP(i, 0, n)
		if (!kill[i])
		{
			vector<pair<int, int> > tmp;
			REP(j, 0, SZ(e[i]))
				if (!kill[e[i][j].x]) tmp.pb(e[i][j]);
			e[i] = tmp;
		}
}

int pre[maxn + 5];

int ans0 = 0, ans1;

void update(const int &x)
{
	if (x > ans0) ans0 = x, ans1 = 1;
	else if (x == ans0) ++ans1;
}

int dis[maxn + 5];

int get(const int &S)
{
	int Max = -1;
	queue<int> q;
	memset(pre, -1, sizeof pre);
	pre[S] = S;
	q.push(S);
	dis[S] = 0;
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		if (Max == -1 || dis[x] > dis[Max]) Max = x;
		REP(i, 0, SZ(e[x]))
		{
			const int &y = e[x][i].x, &z = e[x][i].y;
			if (pre[y] == -1) q.push(y), pre[y] = x, dis[y] = dis[x] + z;
		}
	}
	return Max;
}

int S;

bool in_path[maxn + 5];

int fa[maxn + 5], dep[maxn + 5], sz[maxn + 5] = {0};

int isa[maxn + 5], isb[maxn + 5];

void dfs(int x, int f = -1)
{
	for (auto it : e[x])
	{
		int y = it.x, z = it.y;
		if (y == f) continue;
		dep[y] = dep[x] + z;
		dfs(y, x);
	}
}

void solve()
{
	ans1 = n - m;
	REP(i, 0, n) if (black[i]) { S = i; break; }
	int a = get(S), b = get(a);
	int u = b;
	pre[a] = -1;
	while (u != -1)
	{
		in_path[u] = 1;
		u = pre[u];
	}
	dep[a] = 0;
	dfs(a);
	REP(i, 0, n) if (dep[i] == dep[b]) isb[i] = 1;
	dep[b] = 0;
	dfs(b);
	REP(i, 0, n) if (dep[i] == dep[a]) isa[i] = 1;
	queue<int> q;
	q.push(a);
	dep[a] = 0;
	memset(fa, -1, sizeof fa);
	vector<int> pos;
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		pos.pb(x);
		sz[x] = black[x];
		REP(i, 0, SZ(e[x]))
		{
			const int &y = e[x][i].x, &z = e[x][i].y;
			if (y != fa[x]) q.push(y), fa[y] = x, dep[y] = dep[x] + z;
		}
	}
	for (int i = SZ(pos) - 1; i >= 0; --i)
		if (fa[pos[i]] != -1) 
		{
			sz[fa[pos[i]]] += sz[pos[i]];
			isa[fa[pos[i]]] += isa[pos[i]];
			isb[fa[pos[i]]] += isb[pos[i]];
		}
	REP(i, 0, n)
		if (!black[i] && !kill[i] && !in_path[i])
			update(sz[i]);
	u = b;
	int cntb = 0;
	int cnt = 0;
	while (u != -1)
	{
		if (dep[u] < dep[b] - dep[u]) cntb += sz[u] - cnt;
		sz[u] -= cnt;
		cnt += sz[u];
		u = fa[u];
	}
	u = b;
	int cnta = 0;
	while (u != -1)
	{
		if (dep[u] < dep[b] - dep[u]) cntb -= sz[u];
		if (!black[u]) 
		{
			int tmp = sz[u] + cnta;
			if (isb[u] == isb[a]) tmp += cntb;
			update(tmp);
		}
		if (dep[u] > dep[b] - dep[u]) cnta += sz[u];
		if (isa[u]) cnta = 0;
		u = fa[u];
	}
}

void output()
{
	printf("%d %d\n", ans0, ans1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	prepare();
	solve();
	output();
	return 0;
}