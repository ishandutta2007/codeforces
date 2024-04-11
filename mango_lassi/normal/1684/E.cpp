#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, k;
	cin >> n >> k;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;
	sort(as.begin(), as.end());

	vector<int> cou(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		if (as[i] <= n) ++cou[as[i]];
	}

	// mx: the optimal mex we can get
	int mx = 0, rem = k;
	while(mx < n) {
		if (cou[mx] == 0) --rem;
		if (rem < 0) break;
		++mx;
	}
	
	vector<int> counts;
	for (int i = 0; i < n; ++i) {
		if (as[i] < mx) continue;
		if (i == 0 || as[i] != as[i - 1]) counts.emplace_back(1);
		else ++counts.back();
	}
	sort(counts.begin(), counts.end());

	int res = counts.size();
	for (int i = 0; i < counts.size() && k >= counts[i]; ++i) {
		k -= counts[i];
		--res;
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}