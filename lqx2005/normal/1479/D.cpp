#include<bits/stdc++.h>

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define forgp(u, g, v) for(int iu = 0, v; iu < (int)g[u].size() && (v = g[u][iu], 1); iu++)
#define mp make_pair
#define siz(v) (int)(v).size()
#define x first
#define y second

using namespace std;

typedef unsigned long long u64;
const int N = 3e5 + 10, lg = 20;
mt19937 rnd(time(NULL)); 
struct edge {
	int to, nxt;
}e[N << 1];

int head[N], tot = 0;

int n, q;
int a[N];
int pa[N], bg[N], dep[N], siz[N], top[N];
u64 myr[N];
int rt[N], ls[N * lg], rs[N * lg], idt = 0;
u64 sum[N * lg];

void adde(int u, int v) {
	e[++tot] = edge{v, head[u]};
	head[u] = tot;
}

void ins(int &p, int q, int l, int r, int x) {
	p = ++idt;
	ls[p] = ls[q], rs[p] = rs[q], sum[p] = sum[q] ^ myr[x];
	if(l == r) return;
	int mid = (l + r) / 2;
	if(x <= mid) ins(ls[p], ls[q], l, mid, x);
	else ins(rs[p], rs[q], mid + 1, r, x);
	return;
}

void Dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	pa[u] = fa;
	bg[u] = 0;
	siz[u] = 1;
	ins(rt[u], rt[fa], 1, n, a[u]);
	for(int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if(v == fa) continue;
		Dfs(v, u);
		if(siz[bg[u]] < siz[v]) bg[u] = v;
		siz[u] += siz[v];
	}
	return;
}

void dfs(int u, int tp) {
	top[u] = tp;
	if(bg[u]) dfs(bg[u], tp);
	for(int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if(v == pa[u] || v == bg[u]) continue;
		dfs(v, v);
	}
	return;
}

int LCA(int u, int v) {
	for(; top[u] != top[v]; ) {
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
		u = pa[top[u]];
	}
	if(dep[u] > dep[v]) swap(u, v);
	return u;
}

int query(int p, int q, int l, int r, int L, int R, int x) {
	if(r < L || R < l) return -1;
	u64 a = sum[p] ^ sum[q];
	if(l <= x && x <= r) a ^= myr[x];
	if(!a) return -1;
	if(l == r) return l;
	int mid = (l + r) / 2;
	int pos = -1, t;
	if((t = query(ls[p], ls[q], l, mid, L, R, x)) > 0) pos = t;
	if(pos != -1) return pos;
	if((t = query(rs[p], rs[q], mid + 1, r, L, R, x)) > 0) pos = t;
	return pos;
}


int main() {
	scanf("%d%d", &n, &q);
	rep(i, 1, n) myr[i] = ((u64)rnd() << 32) | rnd();
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		adde(u, v), adde(v, u);
	}
	Dfs(1, 0);
	dfs(1, 1);
	for(; q--; ) {
		int u, v, l, r;
		scanf("%d%d%d%d", &u, &v, &l, &r);
		int lca = LCA(u, v);
		printf("%d\n", query(rt[u], rt[v], 1, n, l, r, a[lca]));
	}
	return 0;
}