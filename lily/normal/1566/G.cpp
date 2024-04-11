#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
void read(int &a) {scanf("%d", &a);}

const int N = 2e5 + 5;
int n, m, Q;

struct edge {
	int u, v, w;
};


set < pair <int, int> > edge[N];
set < pair <int, pair <int, int> > > edges;
map < pair <int, int>, int> wmap;
int clow = INT_MAX, cu = -1, cv = -1; 

struct node {
	int l, r, v;
} c[N * 66];
int ccnt = 0;

int rt[N];
const int rangeL = 1, rangeR = 1e9 + 1;

void upd(int &x, int l, int r, int p, int v) {
	if (!x) x = ++ccnt;
	c[x].v += v;
	if (l < r) {
		int mid = (l + r) / 2;
		if (p <= mid) {
			upd(c[x].l, l, mid, p, v);
		}
		else {
			upd(c[x].r, mid + 1, r, p, v);
		}
	}
}
void add_edge (int u, int v, int w) {
	upd(rt[0], rangeL, rangeR, w, 1);
	upd(rt[u], rangeL, rangeR, w, 1);
	upd(rt[v], rangeL, rangeR, w, 1);
	edge[u].insert ({w, v});
	edge[v].insert ({w, u});
	edges.insert ({w, {u, v}});
}


void remove_edge (int u, int v, int w) {
	upd(rt[0], rangeL, rangeR, w, -1);
	upd(rt[u], rangeL, rangeR, w, -1);
	upd(rt[v], rangeL, rangeR, w, -1);
	edge[u].erase ({w, v});
	edge[v].erase ({w, u});
	edges.erase ({w, {u, v}});
}


int query (int r0, int ru, int rv, int l, int r) {
	if (l == r) return l;
	int mid = (l + r) / 2;
	if (c[c[r0].l].v + (l <= clow && clow <= mid) == c[c[ru].l].v + c[c[rv].l].v) {
		return query (c[r0].r, c[ru].r, c[rv].r, mid + 1, r);
	}
	else {
		return query (c[r0].l, c[ru].l, c[rv].l, l, mid);
	}
}

LL query() {
	int ans = query (rt[0], rt[cu], rt[cv], rangeL, rangeR);
	if (ans == rangeR) return LLONG_MAX;
	return clow + ans;
}

void assert_unique (int u, int v, int w, int x) {
	set <int> s {u, v, w, x};
	assert (s.size() == 4);
}

void get_ans () {
	clow = edges.begin()->first;
	cu = edges.begin()->second.first;
	cv = edges.begin()->second.second;

	LL ans = LLONG_MAX;
	vector < pair <int, int> > ecu, ecv;
	for (auto i : edge[cu]) {if (i.second == cv) continue; ecu.push_back(i); if (ecu.size() == 2) break;}
	for (auto i : edge[cv]) {if (i.second == cu) continue; ecv.push_back(i); if (ecv.size() == 2) break;}
	for (auto i : ecu) {
		for (auto j : ecv) {
			if (j.second == i.second) continue;
			assert_unique (cu, cv, i.second, j.second);
			ans = min(ans, (LL)i.first + j.first);
		}
	}

	for (auto i : ecu) {
		for (auto j : ecu) {
			if (j.second == i.second) continue;
			assert_unique (cu, cv, i.second, j.second);
			ans = min(ans, (long long)clow + i.first + j.first);
		}
	}

	for (auto i : ecv) {
		for (auto j : ecv) {
			if (j.second == i.second) continue;
			assert_unique (cu, cv, i.second, j.second);
			ans = min(ans, (long long)clow + i.first + j.first);
		}
	}

	ans = min(ans, query ());
	printf("%lld\n", ans);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		read(u); read(v); read(w);
		if (u > v) swap(u, v);
		add_edge (u, v, w);
		wmap [ make_pair (u, v)] = w;
	}
	get_ans();
	read(Q);
	for (int t = 1; t <= Q; t++) {
		int k, u, v, w;
		read(k);
		if (k) {
			read(u); read(v); read(w);
			if (u > v) swap(u, v);
			add_edge(u, v, w);
			wmap [make_pair (u, v)] = w;
		} else {
			read(u); read(v);
			if (u > v) swap(u, v);
			remove_edge (u, v, wmap [make_pair (u, v)]);
		}
		get_ans();
	}
}