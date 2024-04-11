#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<ll MOD, ll B>
struct str_hash {
	int n;
	vector<ll> p, h;

	str_hash(vector<int> a) : n(a.size()) {
		p.resize(n, 1);
		for (int i = 1; i < n; i++) p[i] = p[i - 1] * B % MOD;
		h.resize(n + 1, 0);
		for (int i = 0; i < n; i++) h[i + 1] = (h[i] * B + a[i]) % MOD;
	}

	ll get_hash(int L, int R) {
		ll res = h[R] - h[L] * p[R - L] % MOD;
		return res + MOD * (res < 0);
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	str_hash<2286661337, 239> h(a);
	map<int, vector<int>> mapa;
	for (int i = 0; i < n; i++) mapa[a[i]].push_back(i);
	vector<pair<int, int>> segs;
	for (auto [el, poses] : mapa) {
		for (auto i : poses) {
			for (auto j : poses) {
				if (i >= j || 2 * j - i > n) continue;
				if (h.get_hash(i, j) == h.get_hash(j, 2 * j - i))
					segs.emplace_back(i, j);
			}
		}
	}
	sort(segs.begin(), segs.end(), [&](pair<int, int> &a, pair<int, int> &b) {
		return pair<int, int>{a.second - a.first, a.first} < pair<int, int>{b.second - b.first, b.first};
	});
	int left = 0;
	for (auto [L, R] : segs) {
		if (L >= left) left = R;
	}
	cout << n - left << '\n';
	for (int i = left; i < n; i++) cout << a[i] << ' ';
	cout << '\n';
}