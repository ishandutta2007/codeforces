#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> as(n), bs(n);
	for (int& a : as) {
		cin >> a;
		--a;
	}
	for (int& b : bs) {
		cin >> b;
		--b;
	}
	vector<int> rev_bs(n);
	for (int i = 0; i < n; ++i) rev_bs[bs[i]] = i;

	// Compute lengths of cycles
	vector<int> lens;
	for (int i = 0; i < n; ++i) {
		if (bs[i] == -1) continue;
		lens.emplace_back(0);

		for (int x = i; bs[x] != -1; x = rev_bs[as[x]], ++lens.back()) bs[x] = -1;
	}

	int odd_cou = 0;
	for (int l : lens) odd_cou += (l & 1);
	int k = (n - odd_cou) / 2;
	
	ll res = 0;
	for (int i = 0; i < k; ++i) res += 2 * ((n - i) - (i + 1));
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}