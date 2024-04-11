#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()

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

const int MAXN = 120000;

int n, r;
vector<int> eds[MAXN];
int h[MAXN];
int a[MAXN];
vector<int> go[MAXN];
int tin[MAXN];
int tout[MAXN];
int tm1;

void dfs1(int v, int p) {
	tin[v] = tm1++;
	go[h[v]].push_back(v);
	for (int u: eds[v]) {
		if (u == p)
			continue;
		h[u] = h[v] + 1;
		dfs1(u, v);
	}
	tout[v] = tm1;
}

const ll INF = 1e9 + 100;

struct node {
	node *l, *r;
	int mn;
	node() {}
	node(node *l, node *r, int mn): l(l), r(r), mn(mn) {};
};

node *build(int l, int r) {
	if (l + 1 == r)
		return new node(0, 0, INF);
	int m = (l + r) >> 1;
	node *now = new node();
	now->l = build(l, m);
	now->r = build(m, r);
	now->mn = INF;
	return now;
}

node *rt[MAXN];

node *upd(node *v, int l, int r, int x, int y) {
	if (l + 1 == r) {
		return new node(0, 0, y);
	}
	int m = (l + r) >> 1;
	node *now = new node();
	*now = *v;
	now->mn = min(now->mn, y);
	if (x < m) {
		now->l = upd(now->l, l, m, x, y);
	}
	else {
		now->r = upd(now->r, m, r, x, y);
	}
	return now;
}

int get(node *v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return INF;
	if (l <= tl && tr <= r)
		return v->mn;
	int m = (tl + tr) >> 1;
	return min(get(v->l, tl, m, l, r), get(v->r, m, tr, l, r));
}

int main() {
#ifdef BZ
	freopen("in", "r", stdin);
#endif
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> r;
	--r;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	dfs1(r, -1);
	node *root = build(0, n);
	for (int i = 0; i < n; ++i) {
		for (int j: go[i]) {
			root = upd(root, 0, n, tin[j], a[j]);
		}
		rt[i] = root;
	}
	int ans = 0;
	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		a = (a + ans) % n;
		b = (b + ans) % n;
		int mh = min(n - 1, h[a] + b);
		ans = get(rt[mh], 0, n, tin[a], tout[a]);
		cout << ans << "\n";
	}
	return 0;
}