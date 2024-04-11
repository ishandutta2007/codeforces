#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, q;
vector<int> g[N];
int p[N], a[N];
int lev[N];
int id[N], st[N], le[N], ri[N], tot;
int rmq[19][N << 1];
vector<int> vals;

void dfs(int u) {
	le[u] = ++tot; id[tot] = u;
	st[u] = vals.size(); vals.push_back(le[u]);
	for (int v : g[u]) {
		lev[v] = lev[u] + 1;
		dfs(v); vals.push_back(le[u]);
	}
	ri[u] = tot;
}

void prep() {
	for (int i = 0; i < int(vals.size()); ++i) {
		rmq[0][i] = vals[i];
	}
	for (int i = 1; (1 << i) <= int(vals.size()); ++i) {
		for (int j = 0; j + (1 << i) - 1 < int(vals.size()); ++j) {
			rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
		}
	}
}

int get(int l,int r) {
	int LG = __lg(r - l + 1);
	return min(rmq[LG][l], rmq[LG][r - (1 << LG) + 1]);
}

int lca(int u,int v) {
	if (st[u] > st[v]) swap(u, v);
	return id[get(st[u], st[v])];
}

bool isanc(int u,int v) {
	return le[u] <= le[v] && ri[v] <= ri[u];
}

bool onpath(int u,int v,int w) {
	int a = lca(u, v);
	return isanc(a, w) && (isanc(w, u) || isanc(w, v));
}

pair<int,int> merge(pair<int,int> L,pair<int,int> R) {
	if (L.first == 0 || R.first == 0) {
		return make_pair(0, 0);
	}
	if (onpath(L.first, L.second, R.first) && onpath(L.first, L.second, R.second)) {
		return L;
	}
	if (onpath(R.first, R.second, L.first) && onpath(R.first, R.second, L.second)) {
		return R;
	}
	for (int u : {L.first, L.second}) {
		for (int v : {R.first, R.second}) {
			if (onpath(u, v, L.first) && onpath(u, v, L.second)
			&& onpath(u, v, R.first) && onpath(u, v, R.second)) {
				return make_pair(u, v);
			}
		}
	}
	return make_pair(0, 0);
}

pair<int,int> T[N << 2];

void build(int v,int l,int r) {
	if (l == r) {
		T[v] = make_pair(a[l], a[l]);
		return;
	}
	int mid = (l + r) >> 1;
	build(v << 1, l, mid);
	build(v << 1 | 1, mid + 1, r);
	T[v] = merge(T[v << 1], T[v << 1 | 1]);
}

void upd(int v,int l,int r,int p,int a) {
	if (l == r) {
		T[v] = make_pair(a, a); return;
	}
	int mid = (l + r) >> 1;
	if (p <= mid) {
		upd(v << 1, l, mid, p, a);
	} else {
		upd(v << 1 | 1, mid + 1, r, p, a);
	}
	T[v] = merge(T[v << 1], T[v << 1 | 1]);
}

int find(int v,int l,int r,pair<int,int> now) {
	if (l == r) {
		if (merge(now, T[v]).first == 0) {
			return l;
		} else {
			return l + 1;
		}
	}
	int mid = (l + r) >> 1;
	pair<int,int> nxt = merge(now, T[v << 1]);
	if (nxt.first) {
		return find(v << 1 | 1, mid + 1, r, nxt);
	} else {
		return find(v << 1, l, mid, now);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", p + i); a[p[i]] = i;
	}
	for (int i = 2; i <= n; ++i) {
		int p; scanf("%d", &p);
		g[p].push_back(i);
	}
	dfs(1); prep(); 
	build(1, 0, n - 1);
	scanf("%d", &q);
	while (q--) {
		int t; scanf("%d", &t);
		if (t == 1) {
			int u, v; scanf("%d %d", &u, &v);
			swap(p[u], p[v]);
			swap(a[p[u]], a[p[v]]);
			upd(1, 0, n - 1, p[u], a[p[u]]);
			upd(1, 0, n - 1, p[v], a[p[v]]);
		} else {
			printf("%d\n", find(1, 0, n - 1, make_pair(a[0], a[0])));
		}
	}
}