#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

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

int tin[MAXN];
int tout[MAXN];
int h[MAXN];
int gg[MAXN];
int pp[MAXN];
int up[MAXN][LOG];
int gup[MAXN][LOG];
vector<int> eds[MAXN];
int tm1;
vector<int> rmq[MAXN * 4];

void dfs1(int v) {
	tin[v] = tm1++;
	for (int u: eds[v]) {
		h[u] = h[v] + 1;
		dfs1(u);
	}
	tout[v] = tm1;
}

bool is_p(int a, int b) {
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

void dfs2(int v) {
	for (int u: eds[v]) {
		dfs2(u);
		gg[v] = min(gg[v], gg[u]);
	}
}

int mn(int a, int b) {
	if (h[a] < h[b])
		return a;
	else
		return b;
}

void add(int v, int tl, int tr, int x, int y) {
	rmq[v].push_back(y);
	if (tl + 1 == tr)
		return;
	int m = (tl + tr) >> 1;
	if (x < m)
		add(v * 2 + 1, tl, m, x, y);
	else
		add(v * 2 + 2, m, tr, x, y);
}

void build(int v, int tl, int tr) {
	sort(rmq[v].begin(), rmq[v].end());
	if (tl + 1 == tr)
		return;
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
}

int get(int v, int tl, int tr, int l, int r, int l1, int r1) {
	if (r <= tl || tr <= l)
		return 0;
	if (l <= tl && tr <= r) {
		int x = lower_bound(rmq[v].begin(), rmq[v].end(), l1) - rmq[v].begin();
		if (x < rmq[v].size() && rmq[v][x] < r1)
			return 1;
		return 0;
	}
	int m = (tl + tr) >> 1;
	return max(get(v * 2 + 1, tl, m, l, r, l1, r1), get(v * 2 + 2, m, tr, l, r, l1, r1));
}

int n;
int ans[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 1; i < n; ++i) {
		cin >> pp[i];
		--pp[i];
		eds[pp[i]].push_back(i);
	}
	pp[0] = 0;
	for (int i = 0; i < n; ++i)
		up[i][0] = pp[i];
	for (int i = 1; i < LOG; ++i)
		for (int j = 0; j < n; ++j) {
			up[j][i] = up[up[j][i - 1]][i - 1];
		}
	dfs1(0);
	int m;
	cin >> m;
	for (int i = 0; i < n; ++i)
		gg[i] = i;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		int x = lca(a, b);
		gg[a] = mn(gg[a], x);
		gg[b] = mn(gg[b], x);
		add(0, 0, n, tin[a], tin[b]);
		add(0, 0, n, tin[b], tin[a]);
	}
	build(0, 0, n);
	dfs2(0);
	for (int i = 0; i < n; ++i)
		gup[i][0] = gg[i];
	for (int i = 1; i < LOG; ++i)
		for (int j = 0; j < n; ++j)
			gup[j][i] = gup[gup[j][i - 1]][i - 1];
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i)
		ans[i] = -1;
	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		int x = lca(a, b);
		int cur = 0;
		if (h[gup[a][LOG - 1]] > h[x] || h[gup[b][LOG - 1]] > h[x])
			continue;
		if (a != x) {
			for (int i = LOG - 1; i >= 0; --i) {
				if (h[gup[a][i]] > h[x])
					cur += (1 << i), a = gup[a][i];
			}
		}
		if (b != x) {
			for (int i = LOG - 1; i >= 0; --i) {
				if (h[gup[b][i]] > h[x])
					cur += (1 << i), b = gup[b][i];
			}
		}
		if (b == x)
			swap(a, b);
		if (a == x) {
			if (b == x) {
				ans[i] = cur;
				continue;
			}
			else {
				ans[i] = cur + 1;
				continue;
			}
		}
		else {
			if (get(0, 0, n, tin[a], tout[a], tin[b], tout[b]))
				ans[i] = cur + 1;
			else
				ans[i] = cur + 2;
		}
	}
	for (int i = 0; i < q; ++i) {
		cout << ans[i] << "\n";
	}
	return 0;
}