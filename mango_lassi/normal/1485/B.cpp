#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, q, k;
	cin >> n >> q >> k;

	vector<int> as(n);
	for (int& a : as) cin >> a;

	for (int qi = 0; qi < q; ++qi) {
		int l, r;
		cin >> l >> r;
		--l; --r;

		cout << k + (as[r] - as[l] + 1) - 2*(r - l + 1) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}