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

const int MAXN = 110000;
const int LOG = 20;

int r[MAXN];

int n;

pair<int, int> up[MAXN][LOG];

pair<int, int> rmq[LOG][MAXN * 4];

void build(int v, int tl, int tr, int k) {
	if (tl + 1 == tr) {
		rmq[k][v] = up[tl][k];
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m, k);
	build(v * 2 + 2, m, tr, k);
	rmq[k][v].first = min(rmq[k][v * 2 + 1].first, rmq[k][v * 2 + 2].first);
	rmq[k][v].second = max(rmq[k][v * 2 + 1].second, rmq[k][v * 2 + 2].second);
}

pair<int, int> get(int v, int tl, int tr, int k, int l, int r) {
	if (r <= tl || tr <= l)
		return make_pair(n, -1);
	if (l <= tl && tr <= r)
		return rmq[k][v];
	int m = (tl + tr) >> 1;
	auto a = get(v * 2 + 1, tl, m, k, l, r);
	auto b = get(v * 2 + 2, m, tr, k, l, r);
	return {min(a.first, b.first), max(a.second, b.second)};
}


pair<int, int> gget(int l, int r, int x) {
	if (r - l >= n)
		return {0, n};
	else {
		pair<int, int> ans;
		if (l >= 0 && r <= n) {
			ans = get(0, 0, n, x, l, r);
		}
		else if (l < 0) {
			auto a = get(0, 0, n, x, 0, r);
			auto b = get(0, 0, n, x, l + n, n);
			b.first -= n;
			b.second -= n;
			a.first = min(a.first, b.first);
			a.second = max(a.second, b.second);
			ans = a;
		}
		else {
			auto a = get(0, 0, n, x, l, n);
			auto b = get(0, 0, n, x, 0, r - n);
			b.first += n;
			b.second += n;
			a.first = min(a.first, b.first);
			a.second = max(a.second, b.second);
			ans = a;
		}
		if (ans.second - ans.first >= n)
			ans = {0, n};
		return ans;
	}
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	if (n == 1) {
		cout << 0 << "\n";
		return 0;
	}
	for (int i = 0; i < n; ++i)
		cin >> r[i];
	for (int i = 0; i < n; ++i) {
		up[i][0] = make_pair(i - r[i], i + r[i] + 1);
		if (up[i][0].second - up[i][0].first >= n)
			up[i][0] = {0, n};
	}
	for (int i = 1; i < LOG; ++i) {
		build(0, 0, n, i - 1);
		for (int j = 0; j < n; ++j) {
			int l = up[j][i - 1].first;
			int r = up[j][i - 1].second;
			up[j][i] = gget(l, r, i - 1);
		}
	}
	build(0, 0, n, LOG - 1);
	for (int i = 0; i < n; ++i) {
		int ans = 0;
		int l = i;
		int r = i + 1;
		for (int j = LOG - 1; j >= 0; --j) {
			int nl, nr;
			tie(nl, nr) = gget(l, r, j);
			if (nl == 0 && nr == n)
				continue;
			ans += (1 << j);
			l = nl, r = nr;
		}
		cout << ans + 1 << " ";
	}
	cout << "\n";
	return 0;
}