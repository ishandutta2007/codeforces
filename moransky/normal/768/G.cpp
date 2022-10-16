// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 3e5 + 5;

int n, m, q, fa[N], rt, sz[N], dfn[N], dfncnt, son[N], top[N], pre[N];

vector<int> g[N];

void dfs1(int u) {
	sz[u] = 1;
	for (int v: g[u]) {
		if (v == fa[u]) continue;
		dfs1(v);
		sz[u] += sz[v];
		if (sz[v] > sz[son[u]]) son[u] = v;
	}
}

void dfs2(int u, int tp) {
	top[u] = tp;
	dfn[u] = ++dfncnt;
	pre[dfn[u]] = u;
	if (son[u]) 
		dfs2(son[u], tp);
	for (int v: g[u]) {
		if (v == son[u] || v == fa[u]) continue;
		dfs2(v, v);
	}
}

int Rt[N], idx;

struct T{
	int l, r, v;
} t[N * 20];

#define ls t[p].l
#define rs t[p].r

void ins(int &p, int q, int l, int r, int x) {
	t[p = ++idx] = t[q];
	t[p].v++;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (x <= mid) ins(ls, t[q].l, l, mid, x);
	else ins(rs, t[q].r, mid + 1, r, x);
}

int tot;

PII e[N], d[N];

int queryMx(int p, int q, int l, int r, int x, int y) {
	if (y < l || x > r || x > y) return 0;
	int s = t[p].v - t[q].v;
	if (!s) return 0;
	if (l == r) return r;
	int mid = (l + r) >> 1;
	int ret = queryMx(rs, t[q].r, mid + 1, r, x, y);
	if (ret) return ret;
	return queryMx(ls, t[q].l, l, mid, x, y);	
}

int queryMn(int p, int q, int l, int r, int x, int y) {
	if (y < l || x > r || x > y) return 0;
	int s = t[p].v - t[q].v;
	if (!s) return 0;
	if (l == r) return r;
	int mid = (l + r) >> 1;
	int ret = queryMn(ls, t[q].l, l, mid, x, y);
	if (ret) return ret;
	return queryMn(rs, t[q].r, mid + 1, r, x, y);	
}


int inline ask2(int mn, int mx, int o) {
	int A = (mx - mn) / 2 + o;
	int x = 0;
	for (int i = 1; i <= tot; i++) chkMax(x, queryMx(Rt[e[i].se], Rt[e[i].fi - 1], 1, n, 1, A));
	int ans = mx;
	x -= o;
	chkMin(ans, max(mn + x, mx - x));
	x = 2e9;
	for (int i = 1; i <= tot; i++) {
		int ret = queryMn(Rt[e[i].se], Rt[e[i].fi - 1], 1, n, A + 1, n);
		//cout << ret << " md\n";
		if (ret) chkMin(x, ret);
	}
	x -= o;
	chkMin(ans, max(mn + x, mx - x));
	return ans;
}

int inline solve1(int u, int mn) {
	int x = fa[u]; tot = 0;
	while (x) {
		e[++tot] = mp(dfn[top[x]], dfn[x]);
		x = fa[top[x]];
	}
	int ans = 2e9;
	chkMin(ans, ask2(mn, n - sz[u], sz[u]));
	//cout << "miao" << u << " " << ans << " ???\n";
	for (int i = 1; i <= tot; i++) d[i] = e[i];
	int len = tot;
	d[++len] = mp(dfn[u], dfn[u] + sz[u] - 1);
	tot = 0; 
	sort(d + 1, d + 1 + len);
	if (d[1].fi > 1) e[++tot] = mp(1, d[1].fi - 1);
	if (d[len].se < n) e[++tot] = mp(d[len].se + 1, n);
	for (int i = 1; i < len; i++) {
		if (d[i].se + 1 < d[i + 1].fi) e[++tot] = mp(d[i].se + 1, d[i + 1].fi - 1);
	}
	chkMin(ans, ask2(mn, n - sz[u], 0));
	return ans;
}

int inline solve2(int u, int mn, int v) {
	tot = 0;
	e[++tot] = mp(dfn[v], dfn[v] + sz[v] - 1);
	return ask2(mn, sz[v], 0);
}

int main() {
	//freopen("1.in", "r", stdin);
	read(n);
	for (int i = 1; i <= n; i++) {
		int u, v; read(u), read(v);
		fa[v] = u;
		if (u) g[u].pb(v), g[v].pb(u);
		else rt = v;
	}
	if (n == 1) {
		puts("0");
		return 0;
	}
	dfs1(rt);
	dfs2(rt, rt);
	for (int i = 1; i <= n; i++) ins(Rt[i], Rt[i - 1], 1, n, sz[pre[i]]);
	for (int u = 1; u <= n; u++) {
		vector<PII> a;
		for (int v: g[u]) {
			if (v == fa[u]) a.pb(mp(n - sz[u], fa[u]));
			else a.pb(mp(sz[v], v));
		}
		sort(a.begin(), a.end());
		if (a.size() == 1) {
			printf("%d\n", a[0].fi);
			continue;
		}
		int s = 0;
		if (a.size() > 2) s = a[a.size() - 2].fi;
		int ans = 2e9;
		if (a.back().se == fa[u]) chkMin(ans, solve1(u, a[0].fi));
		else chkMin(ans, solve2(u, a[0].fi, a.back().se));
		int ot = max(ans, s);
		printf("%d\n", ot);
	}
    return 0;
}