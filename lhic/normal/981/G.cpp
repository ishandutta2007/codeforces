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
const ll MOD = 998244353;

set<pair<int, int> > ss[MAXN];
ll ad[MAXN * 4];
ll sm[MAXN * 4];
ll ml[MAXN * 4];

void build(int v, int tl, int tr) {
	ml[v] = 1;
	ad[v] = 0;
	sm[v] = 0;
	if (tl + 1 == tr)
		return;
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
}

void push(int v, int tl, int tr) {
	if (ml[v] != 1) {
		ml[v * 2 + 1] = (ml[v * 2 + 1] * ml[v]) % MOD;
		ml[v * 2 + 2] = (ml[v * 2 + 2] * ml[v]) % MOD;
		ad[v * 2 + 1] = (ad[v * 2 + 1] * ml[v]) % MOD;
		ad[v * 2 + 2] = (ad[v * 2 + 2] * ml[v]) % MOD;
		sm[v * 2 + 1] = (sm[v * 2 + 1] * ml[v]) % MOD;
		sm[v * 2 + 2] = (sm[v * 2 + 2] * ml[v]) % MOD;
		ml[v] = 1;
	}
	if (ad[v] != 0) {
		int m = (tl + tr) >> 1;
		ad[v * 2 + 1] = (ad[v * 2 + 1] + ad[v]) % MOD;
		ad[v * 2 + 2] = (ad[v * 2 + 2] + ad[v]) % MOD;
		sm[v * 2 + 1] = (sm[v * 2 + 1] + ad[v] * (m - tl)) % MOD;
		sm[v * 2 + 2] = (sm[v * 2 + 2] + ad[v] * (tr - m)) % MOD;
		ad[v] = 0;
	}
}

void add(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		ad[v] = (ad[v] + 1) % MOD;
		sm[v] = (sm[v] + tr - tl) % MOD;
		return;
	}
	int m = (tl + tr) >> 1;
	push(v, tl, tr);
	add(v * 2 + 1, tl, m, l, r);
	add(v * 2 + 2, m, tr, l, r);
	sm[v] = (sm[v * 2 + 1] + sm[v * 2 + 2]) % MOD;
}

void mult(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		ad[v] = (ad[v] * 2) % MOD;
		ml[v] = ml[v] * 2 % MOD;
		sm[v] = (sm[v] * 2) % MOD;
		return;
	}
	int m = (tl + tr) >> 1;
	push(v, tl, tr);
	mult(v * 2 + 1, tl, m, l, r);
	mult(v * 2 + 2, m, tr, l, r);
	sm[v] = (sm[v * 2 + 1] + sm[v * 2 + 2]) % MOD;
}

ll get(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return 0;
	if (l <= tl && tr <= r)
		return sm[v];
	int m = (tl + tr) >> 1;
	push(v, tl, tr);
	return (get(v * 2 + 1, tl, m, l, r) + get(v * 2 + 2, m, tr, l, r)) % MOD;
}

int n, q;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> q;
	build(0, 0, n);
	for (int i = 0; i < q; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			--l;
			--x;
			vector<pair<int, int>> vv;
			auto it = ss[x].lower_bound(make_pair(l, 0));
			if (it != ss[x].begin())
				--it;
			if (it != ss[x].end() && it->second < l)
				++it;
			while (it != ss[x].end() && it->first <= r) {
				vv.push_back(*it);
				ss[x].erase(it++);
			}
			for (int i = 0; i < vv.size(); ++i) {
				int lb = max(l, vv[i].first);
				int rb = min(r, vv[i].second);
				mult(0, 0, n, lb, rb);
			}
			for (int i = 0; i < (int)vv.size() - 1; ++i) {
				add(0, 0, n, vv[i].second, vv[i + 1].first);
			}
			if (vv.empty()) {
				add(0, 0, n, l, r);
			}
			if (vv.size() >= 1 && vv[0].first > l)
				add(0, 0, n, l, vv[0].first);
			if (vv.size() >= 1 && vv.back().second < r)
				add(0, 0, n, vv.back().second, r);
			if (vv.size()) {
				l = min(l, vv[0].first);
				r = max(r, vv.back().second);
			}
			ss[x].insert(make_pair(l, r));
		}
		else {
			int l, r;
			cin >> l >> r;
			--l;
			cout << get(0, 0, n, l, r) << "\n";
		}
	}
	return 0;
}