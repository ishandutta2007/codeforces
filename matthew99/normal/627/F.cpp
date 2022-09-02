#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
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

const int maxn = 200000;

struct edge
{
	int id, nxt;

	edge() { }
	edge(int _id, int _nxt): id(_id), nxt(_nxt) { }

};

edge e[(maxn << 1) + 5];
int st[maxn + 5], en = 0;

inline void add_edge(int x, int y)
{
	e[en] = edge(y, st[x]), st[x] = en++;
}

int n;

int dep[maxn + 5], fa[maxn + 5];

int dfs_tot = 0;
int dfn[maxn + 5], End[maxn + 5];

void dfs(int x, int f = -1)
{
	if (~f) dep[x] = dep[f] + 1;
	else dep[x] = 0;
	dfn[x] = dfs_tot++;
	fa[x] = f;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == f) continue;
		dfs(y, x);
	}
	End[x] = dfs_tot;
}

int pa, pb;
int a[maxn + 5], b[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(st, -1, sizeof st), en = 0;
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	pa = find(a, a + n, 0) - a;
	REP(i, 0, n) scanf("%d", b + i);
	pb = find(b, b + n, 0) - b;
	REP(i, 0, n - 1)
	{
		int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		add_edge(x, y), add_edge(y, x);
	}
	dfs(pb);
	int u = pa;
	while (u != pb)
	{
		a[u] = a[fa[u]];
		u = fa[u];
	}
	a[u] = 0;
	int x = -1, rt = -1;
	int cnt = 0;
	REP(i, 0, n) if (a[i] != b[i])
	{
		++cnt;
		if (!~rt || dep[i] < dep[rt]) rt = i;
		if (!~x || dep[i] > dep[x]) x = i;
	}
	if (!cnt) EXIT("0 %d\n", dep[pa]);
	assert(x != -1 && rt != -1);
	if (!~fa[rt]) EXIT("-1\n");
	rt = fa[rt];
	int y = rt;
	REP(i, 0, n) if (a[i] != b[i] && (End[i] <= dfn[x] || dfn[i] > dfn[x]) && dep[i] > dep[y]) y = i;
	if (dep[x] + dep[y] - (dep[rt] << 1) != cnt) EXIT("-1\n");
	vector<int> all;
	int id = x;
	while (id != rt)
	{
		all.pb(id);
		id = fa[id];
	}
	reverse(ALL(all));
	id = y;
	while (id != rt)
	{
		all.pb(id);
		id = fa[id];		
	}
	int go = -1;
	REP(i, 0, SZ(all))
		if (a[all[0]] == b[all[i]])
		{
			go = i;
			break;
		}
	if (!~go) EXIT("-1\n");
	REP(i, 0, SZ(all))
		if (a[all[i]] != b[all[(i + go) % SZ(all)]]) EXIT("-1\n");
	LL ans = dep[pa];
	static bool vis[maxn + 5];
	memset(vis, 0, sizeof vis);
	id = pa;
	while (~id)
	{
		vis[id] = 1;
		id = fa[id];
	}
	if (vis[all[0]] || vis[all.back()])
	{
		if (vis[all.back()]) reverse(ALL(all)), go = SZ(all) - go;
		int tmp = SZ(all);
		REP(i, 1, SZ(all)) if (!vis[all[i]]) { tmp = i; break; }
		int cyc_len = SZ(all) + 1;
		ans -= tmp;
		ans += min(abs(tmp + (LL)go * cyc_len), abs(tmp + (LL)(go - SZ(all)) * cyc_len));
	}
	else ans += min(go, SZ(all) - go) * (cnt + 1);
	id = rt;
	while (!vis[id])
	{
		ans += 2;
		id = fa[id];
	}
	if (x > y) swap(x, y);
	printf("%d %d %I64d\n", x + 1, y + 1, ans);
	return 0;
}