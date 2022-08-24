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

const int MAXN = 120000;
int tin[MAXN], tout[MAXN];
int sz[MAXN], pp[MAXN];
int tm1;
vector<int> eds[MAXN];
int nowc = 0;
int n;
int gr[MAXN];
int pl[MAXN];
vector<int> gvv[MAXN];
const ll INF = 1e18;

struct path {
	int p;
	vector<int> vv;
	vector<pair<ll, int>> rmq;
	vector<ll> ad;
	void build(int v, int tl, int tr) {
		ad[v] = 0;
		if (tl + 1 == tr) {
			if (!gvv[vv[tl]].empty())
				rmq[v] = {gvv[vv[tl]].back(), vv[tl]};
			else
				rmq[v] = {INF, -1};
			return;
		}
		int m = (tl + tr) >> 1;
		build(v * 2 + 1, tl, m);
		build(v * 2 + 2, m, tr);
		rmq[v] = min(rmq[v * 2 + 1], rmq[v * 2 + 2]);
	}
	void init(int k) {
		for (int i = 0; i < vv.size(); ++i)
			gr[vv[i]] = k, pl[vv[i]] = i;
		rmq.resize(vv.size() * 4);
		ad.resize(vv.size() * 4);
		build(0, 0, vv.size());
	}
	pair<ll, int> get(int v, int tl, int tr, int l, int r) {
		if (r <= tl || tr <= l)
			return {INF, -1};
		if (l <= tl && tr <= r) {
			return rmq[v];
		}
		int m = (tl + tr) >> 1;
		auto ans = min(get(v * 2 + 1, tl, m, l, r), get(v * 2 + 2, m, tr, l, r));
		ans.first += ad[v];
		return ans;
	}
	pair<ll, int> get(int l, int r) {
		return get(0, 0, vv.size(), l, r);
	}
	void add(int v, int tl, int tr, int l, int r, ll k) {
		if (r <= tl || tr <= l)
			return;
		if (l <= tl && tr <= r) {
			ad[v] += k;
			rmq[v].first += k;
			return;
		}
		int m = (tl + tr) >> 1;
		add(v * 2 + 1, tl, m, l, r, k);
		add(v * 2 + 2, m, tr, l, r, k);
		rmq[v] = min(rmq[v * 2 + 1], rmq[v * 2 + 2]);
		rmq[v].first += ad[v];
	}
	void add(int l, int r, ll k) {
		add(0, 0, vv.size(), l, r, k);
	}
	void upd(int v, int tl, int tr, int x) {
		if (tl + 1 == tr) {
			if (!gvv[vv[tl]].empty())
				rmq[v] = {gvv[vv[tl]].back() + ad[v], vv[tl]};
			else
				rmq[v] = {INF, -1};
			return;
		}
		int m = (tl + tr) >> 1;
		if (x < m)
			upd(v * 2 + 1, tl, m, x);
		else
			upd(v * 2 + 2, m, tr, x);
		rmq[v] = min(rmq[v * 2 + 1], rmq[v * 2 + 2]);
		rmq[v].first += ad[v];
	}
	void del(int k) {
		gvv[vv[k]].pop_back();
		upd(0, 0, vv.size(), k);
	}
};

path gg[MAXN];

bool is_p(int a, int b) {
	return tin[a] <= tin[b] && tin[b] < tout[a];
}

void dfs0(int v, int p) {
	tin[v] = tm1++;
	sz[v] = 1;
	for (int u: eds[v]) {
		if (u != p) {
			dfs0(u, v);
			sz[v] += sz[u];
		}
	}
	tout[v] = tm1;
}

void dfs1(int v, int p, int cur) {
	pp[v] = p;
	if (cur == -1) {
		cur = nowc++;
		gg[cur].p = v;
	}
	gg[cur].vv.push_back(v);
	int bst = -1;
	for (int u: eds[v]) {
		if (u == p)
			continue;
		if (bst == -1 || sz[u] > sz[bst])
			bst = u;
	}
	if (bst != -1) {
		dfs1(bst, v, cur);
	}
	else {
		gg[cur].init(cur);
	}
	for (int u: eds[v]) {
		if (u == p || u == bst)
			continue;
		dfs1(u, v, -1);
	}
}

void build() {
	dfs0(0, -1);
	dfs1(0, -1, -1);
}

ll rmq[MAXN * 4];

ll get2(int v, int tl, int tr, int x) {
	if (tl + 1 == tr)
		return rmq[v];
	int m = (tl + tr) >> 1;
	if (x < m)
		return get2(v * 2 + 1, tl, m, x) + rmq[v];
	else
		return get2(v * 2 + 2, m, tr, x) + rmq[v];
}

void add2(int v, int tl, int tr, int l, int r, ll k) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		rmq[v] += k;
		return;
	}
	int m = (tl + tr) >> 1;
	add2(v * 2 + 1, tl, m, l, r, k);
	add2(v * 2 + 2, m, tr, l, r, k);
}

int get(int a, int b) {
	int bst = -1;
	int pos = n + 1;
	ll bx = 1e18;
	while (gr[a] != gr[b]) {
		if (is_p(gg[gr[a]].p, b))
			swap(a, b);
		ll ad = get2(0, 0, n, tin[gg[gr[a]].p]);
		int g = gr[a];
		pair<ll, int> x = gg[g].get(0, pl[a] + 1);
		x.first += ad;
		if (x.second != -1) {
			if (x < make_pair(bx, pos)) {
				bx = x.first;
				pos = x.second;
				bst = gvv[x.second].back();
			}
		}
		a = pp[gg[g].p];
	}
	if (is_p(a, b))
		swap(a, b);
	ll ad = get2(0, 0, n, tin[gg[gr[a]].p]);
	int g = gr[a];
	pair<ll, int> x = gg[g].get(pl[b], pl[a] + 1);
	x.first += ad;
	if (x.second != -1) {
		if (x < make_pair(bx, pos)) {
			bx = x.first;
			pos = x.second;
			bst = gvv[x.second].back();
		}
	}
	if (bst == -1)
		return -1;
	gg[gr[pos]].del(pl[pos]);
	return bst;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	int m, q;
	cin >> n >> m >> q;
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	for (int i = 0; i < m; ++i) {
		int c;
		cin >> c;
		--c;
		gvv[c].push_back(i + 1);
	}
	for (int i = 0; i < n; ++i)
		reverse(gvv[i].begin(), gvv[i].end());
	build();
	for (int i = 0; i < q; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			int a, b, k;
			cin >> a >> b >> k;
			--a, --b;
			vector<int> vv;
			for (int i = 0; i < k; ++i) {
				int x = get(a, b);
				if (x == -1)
					break;
				vv.push_back(x);
			}
			cout << vv.size() << " ";
			for (int i: vv)
				cout << i << " ";
			cout << "\n";
		}
		else {
			int a;
			ll k;
			cin >> a >> k;
			--a;
			int g = gr[a];
			if (gg[g].p != a) {
				gg[g].add(pl[a], gg[g].vv.size(), k);
			}
			add2(0, 0, n, tin[a], tout[a], k);
		}
	}
	return 0;
}