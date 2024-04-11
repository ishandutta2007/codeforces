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

const int MAXN = 510000;

ll hh[MAXN];
int n, q;
int p[MAXN];
ll w[MAXN];

vector<int> eds[MAXN];

int tm1;
int tin[MAXN];
int tout[MAXN];
vector<int> vv;

void dfs1(int v) {
	tin[v] = tm1++;
	if (eds[v].empty())
		vv.push_back(v);
	for (int u: eds[v]) {
		dfs1(u);
	}
	tout[v] = tm1;
}

vector<tuple<int, int, int>> go[MAXN];

ll rmq[MAXN * 4];
ll dd[MAXN * 4];
const ll INF = 1e17;

void build(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		rmq[v] = hh[vv[tl]];
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	rmq[v] = min(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

void add(int v, int tl, int tr, int l, int r, ll d) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		dd[v] += d;
		rmq[v] += d;
		return;
	}
	int m = (tl + tr) >> 1;
	add(v * 2 + 1, tl, m, l, r, d);
	add(v * 2 + 2, m, tr, l, r, d);
	rmq[v] = min(rmq[v * 2 + 1], rmq[v * 2 + 2]) + dd[v];
}

ll get(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return INF;
	if (l <= tl && tr <= r)
		return rmq[v];
	int m = (tl + tr) >> 1;
	return min(get(v * 2 + 1, tl, m, l, r), get(v * 2 + 2, m, tr, l, r)) + dd[v];
}
ll ans[MAXN];

void dfs2(int v) {
	int lb = lower_bound(ALL(vv), tin[v]) - vv.begin();
	int rb = lower_bound(ALL(vv), tout[v]) - vv.begin();
	add(0, 0, vv.size(), lb, rb, -2 * w[v]);
	for (auto q: go[v]) {
		int l, r, k;
		tie(l, r, k) = q;
		l = lower_bound(ALL(vv), l) - vv.begin();
		r = lower_bound(ALL(vv), r) - vv.begin();
		ans[k] = get(0, 0, vv.size(), l, r) + hh[v];
	}
	for (int u: eds[v]) {
		dfs2(u);
	}
	add(0, 0, vv.size(), lb, rb, 2 * w[v]);
}


int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> q;
	for (int i = 1; i < n; ++i) {
		cin >> p[i] >> w[i];
		--p[i];
		hh[i] = hh[p[i]] + w[i];
		eds[p[i]].emplace_back(i);
	}
	dfs1(0);
	for (int i = 0; i < q; ++i) {
		int v, l, r;
		cin >> v >> l >> r;
		--l;
		--v;
		go[v].emplace_back(l, r, i);
	}
	build(0, 0, vv.size());
	dfs2(0);
	for (int i = 0; i < q; ++i)
		cout << ans[i] << "\n";
	return 0;
}