#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int MAXN = 210000;
const int LOG = 20;

int n, q;
vector<int> eds[MAXN];

set<pair<int, int>> ss;
int h[MAXN];
int up[MAXN][LOG];
int tin[MAXN];
int tout[MAXN];
int tm1;

void dfs1(int v, int p) {
	tin[v] = tm1++;
	for (int i = 1; i < LOG; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];
	for (int u: eds[v]) {
		if (u == p)
			continue;
		h[u] = h[v] + 1;
		up[u][0] = v;
		dfs1(u, v);
	}
	tout[v] = tm1;
}

int is_p(int a, int b) {
	return tin[a] <= tin[b] && tin[b] < tout[a];
}

int lca(int a, int b) {
	if (is_p(a, b))
		return a;
	if (is_p(b, a))
		return b;
	for (int i = LOG - 1; i >= 0; --i) {
		if (!is_p(up[a][i], b))
			a = up[a][i];
	}
	return up[a][0];
}

int go(int x, int g) {
	for (int i = LOG - 1; i >= 0; --i) {
		if (g >= (1 << i))
			g -= (1 << i), x = up[x][i];
	}
	return x;
}


pair<int, int> rmq[MAXN * 4];
int dd[MAXN * 4];

void push(int v) {
	if (dd[v]) {
		dd[v * 2 + 1] += dd[v];
		dd[v * 2 + 2] += dd[v];
		rmq[v * 2 + 1].first += dd[v];
		rmq[v * 2 + 2].first += dd[v];
		dd[v] = 0;
	}
}

pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return {a.first, a.second + b.second};
	return max(a, b);
}

void add(int v, int tl, int tr, int l, int r, int d) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		dd[v] += d;
		rmq[v].first += d;
		return;
	}
	int m = (tl + tr) >> 1;
	push(v);
	add(v * 2 + 1, tl, m, l, r, d);
	add(v * 2 + 2, m, tr, l, r, d);
	rmq[v]= merge(rmq[v * 2 + 1], rmq[v * 2 + 2]);
	rmq[v].first += dd[v];
}

void build(int v, int tl, int tr) {
	rmq[v] = make_pair(0, tr - tl);
	if (tl + 1 == tr) {
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> q;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	build(0, 0, n);
	dfs1(0, -1);
	int cur = 0;
	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		if (a > b)
			swap(a, b);
		if (!ss.count({a, b})) {
			ss.insert({a, b});
			int x = lca(a, b);
			if (x == a || x == b) {
				if (x == b)
					swap(a, b);
				x = go(b, h[b] - h[a] - 1);
				add(0, 0, n, tin[x], tout[x], -1);
				add(0, 0, n, tin[b], tout[b], 1);
			}
			else {
				++cur;
				add(0, 0, n, tin[a], tout[a], 1);
				add(0, 0, n, tin[b], tout[b], 1);
			}
		}
		else {
			ss.erase({a, b});
			int x = lca(a, b);
			if (x == a || x == b) {
				if (x == b)
					swap(a, b);
				x = go(b, h[b] - h[a] - 1);
				add(0, 0, n, tin[x], tout[x], 1);
				add(0, 0, n, tin[b], tout[b], -1);
			}
			else {
				--cur;
				add(0, 0, n, tin[a], tout[a], -1);
				add(0, 0, n, tin[b], tout[b], -1);
			}
		}
		if (rmq[0].first == cur)
			cout << rmq[0].second << "\n";
		else
			cout << 0 << "\n";
	}
	return 0;
}