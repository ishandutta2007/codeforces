#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> c0(n, 0), c1(m, 0);
	for (int i = 0; i < k; ++i) {
		int a;
		cin >> a;
		++c0[a-1];
	}
	for (int i = 0; i < k; ++i) {
		int b;
		cin >> b;
		++c1[b-1];
	}
	ll res = (ll)k * (k-1) / 2;
	for (auto v : c0) res -= (ll)v * (v-1) / 2;
	for (auto v : c1) res -= (ll)v * (v-1) / 2;
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}