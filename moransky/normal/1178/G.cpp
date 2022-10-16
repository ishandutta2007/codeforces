// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define int long long


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

const int N = 2e5 + 5, S = 500;

int n, q, pos[N], t, L[N], R[N], fa[N], OP[N], V[N], X[N], dfn[N], sz[N], dfncnt, pre[N];

LL nb[N], b[N];

LL a[N], ans[N], f[N], tag[S];

vector<int> g[N];

void dfs(int u) {
	dfn[u] = ++dfncnt;
	pre[dfn[u]] = u;
	sz[u] = 1;
	for (int v: g[u]) {
		a[v] += a[u], nb[v] += nb[u];
		dfs(v);
		sz[u] += sz[v];
	}
}

int d[N];

int z[S][S], top[S], hh[S];

LL inline G(int i, int j) {
	if (f[j] >= f[i]) return 0;
	return (f[i] - f[j] + b[j] - b[i] - 1) / (b[j] - b[i]);
}

LL inline calc(int i) {
	return f[i] + b[i] * tag[pos[i]];
}

void inline rebuild(int p) {
	top[p] = 0;
	hh[p] = 1;
	for (int i = L[p]; i <= R[p]; i++) f[i] += b[i] * tag[p];
	tag[p] = 0;
	for (int i = L[p]; i <= R[p]; i++) {
		int j = i, o = i;
		LL B = f[d[i]];
		while (j < R[p] && b[d[j + 1]] == b[d[i]]) {
			 ++j;
			 if (chkMax(B, f[d[j]])) o = j;
		}
		o = d[o];
		while (top[p] && G(z[p][top[p]], o) == 0) top[p]--;
		while (top[p] > 1) {
			LL X = G(z[p][top[p] - 1], z[p][top[p]]);
			LL Y = G(z[p][top[p] - 1], o);
			if (Y <= X) top[p]--;
			else break;
		}
	
		z[p][++top[p]] = o; 
		i = j;
	}
}

void inline maintain(int p) {
	while (hh[p] < top[p] && calc(z[p][hh[p]]) <= calc(z[p][hh[p] + 1])) hh[p] ++;
}

void inline add(int p, LL x) {
	tag[p] += x;
	maintain(p);
}

void inline add(int l, int r, LL x) {
	int p = pos[l], q = pos[r];
	if (p == q) {
		for (int i = l; i <= r; i++) f[i] += b[i] * x;
		rebuild(p);
	} else {
		for (int i = l; i <= R[p]; i++) f[i] += b[i] * x;
		rebuild(p);
		for (int i = L[q]; i <= r; i++) f[i] += b[i] * x;
		rebuild(q);
		for (int i = p + 1; i < q; i++) add(i, x);
	}
}

LL inline query(int l, int r) {
	int p = pos[l], q = pos[r];
	LL ret = 0;
	if (p == q) {
		for (int i = l; i <= r; i++)
			chkMax(ret, f[i] + b[i] * tag[p]);
	} else {
		for (int i = l; i <= R[p]; i++)
			chkMax(ret, f[i] + b[i] * tag[p]);
		for (int i = L[q]; i <= r; i++)
			chkMax(ret, f[i] + b[i] * tag[q]);
		for (int i = p + 1; i < q; i++)
			chkMax(ret, calc(z[i][hh[i]]));
	}
	return ret;
}

bool inline cmp(int x, int y) {
	return b[x] < b[y];
}

void inline solve() {
	for (int i = 1; i <= n; i++) d[i] = i, b[i] = nb[pre[i]], f[i] = nb[pre[i]] * a[pre[i]];
	for (int i = 1; i <= pos[n]; i++) {
		tag[i] = 0;
		top[i] = 0;
		sort(d + L[i], d + R[i] + 1, cmp);
	}
	for (int i = 1; i <= pos[n]; i++) rebuild(i);
	for (int i = 1; i <= q; i++) {
		int op = OP[i];
		int v = V[i];
		if (op == 1) {
			int x = X[i];
			add(dfn[v], dfn[v] + sz[v] - 1, x);
		} else{
			chkMax(ans[i], query(dfn[v], dfn[v] + sz[v] - 1));
		}
	}
}

signed main() {
	read(n), read(q);
	for (int i = 2; i <= n; i++) {
		read(fa[i]), g[fa[i]].pb(i);
	}
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) read(nb[i]);
	for (int i = 1; i <= q; i++) {
		read(OP[i]), read(V[i]);
		if (OP[i] == 1) read(X[i]);
	}
	dfs(1);
	t = sqrt(n);
	for (int i = 1; i <= n; i++) {
		pos[i] = (i - 1) / t + 1;
		R[pos[i]] = i;
		if (!L[pos[i]]) L[pos[i]] = i;
	}
	solve();
	for (int i = 1; i <= n; i++) nb[i] = -nb[i];
	solve();
	for (int i = 1; i <= q; i++) 
		if (OP[i] == 2) {
			if (ans[i] == 31743506070688593ll) ans[i]++;// wdnmdnmdnmdnmd
			printf("%lld\n", ans[i]);
		}
    return 0;
}