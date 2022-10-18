// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

#define int long long

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
const int N = 2e5 + 5;

int n, k;

int head[N], numE = 1;

struct E{
    int next, v;
} e[N << 1];

void add(int u, int v) {
    e[++numE] = (E) { head[u], v };
    head[u] = numE;
}



int sz[N], fa[N], dep[N], top[N], hson[N], pre[N], dfn[N], dfncnt;
LL ans = -1e18;
void dfs1(int u) {
    sz[u] = 1;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v;
        if (v == fa[u]) continue;
        dep[v] = dep[u] + 1, fa[v] = u;
        dfs1(v);
        sz[u] += sz[v];
        if (sz[v] > sz[hson[u]]) hson[u] = v;
    }
}

void dfs2(int u, int tp) {
    top[u] = tp;
    dfn[u] = ++dfncnt;
    pre[dfn[u]] = u;
    if (hson[u]) dfs2(hson[u], tp);
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v;
        if (v == fa[u] || v == hson[u]) continue;
        dfs2(v, v);
    }
}



#define ls (p << 1)
#define rs (p << 1 | 1)

int mx[N << 2], w[N << 2], tag[N << 2];

void inline pushup(int p) {
	mx[p] = max(mx[ls], mx[rs]);
	if (mx[ls] == mx[rs]) {
		int A = w[ls], B = w[rs];
		w[p] = dep[A] > dep[B] ? A : B; 
	} else if (mx[p] == mx[ls]) w[p] = w[ls];
	else w[p] = w[rs];
}

void inline Add(int p, int k) {
	tag[p] += k;
	mx[p] += k;
}

void inline pushdown(int p) {
	if (tag[p]) {
		Add(ls, tag[p]);
		Add(rs, tag[p]);
		tag[p] = 0;
	}
}

void build(int p, int l, int r) {
	if(l == r) { 
		w[p] = pre[r];
		return; 
	}
	int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    pushup(p);
}
void change(int p, int l, int r, int x, int y, int k) {
    if(x <= l && r <= y) {
    	Add(p, k);
        return ;
    }
    int mid = (l + r) >> 1;
    pushdown(p);
    if(x <= mid) change(p << 1, l, mid, x, y, k);
    if(mid + 1 <= y) change(p << 1 | 1, mid + 1, r, x, y, k);
    pushup(p);
}

const int INF = 1e9;

int vis[N];
int W;
void inline del(int i) {
	if (vis[i] == 1) W--, vis[i] = 2, cout << i << " sima\n";
	change(1, 1, n, dfn[i], dfn[i], -INF);
	i = fa[i];
	while (i && !vis[i]) {
		vis[i] = 1;
		if (sz[i] > 1) change(1, 1, n, dfn[i] + 1, dfn[i] + sz[i] - 1, -1);
		i = fa[i];
	}
}

LL inline get(int r, int b) {
	return ((LL)n - r - b) * (r - b);
}

void inline cz(int r, int b) {
	LL v = 9e18;
	chkMin(v, get(r, 0));
	chkMin(v, get(r, b));
	int t = n / 2;
	if (t <= b)
	chkMin(v, get(r, t));
	chkMax(ans, v);
}

signed main() {
	read(n), read(k);
	for (int i = 1; i < n; i++) {
		int u, v; read(u), read(v);
		add(u, v), add(v, u);
	}
	dfs1(1);
	dfs2(1, 1);
	build(1, 1, n);
	for (int i = 1; i <= n; i++)
		if (sz[i] > 1) change(1, 1, n, dfn[i] + 1, dfn[i] + sz[i] - 1, 1);
	W = 0;
	cz(0, n);
	for (int r = 1; r <= k; r++) {
		int u = w[1];
		W += mx[1];
		
		if (mx[1]) del(u);
		cz(r, n - r - W);
	}
	printf("%lld\n", ans);
    return 0;
}