#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	ll x;
	cin >> n >> x;
	multiset<ll> nums;
	for (int i = 0; i < n; ++i) {
		ll v;
		cin >> v;
		nums.insert(v);
	}

	int res = 0;
	while(! nums.empty()) {
		auto it = nums.begin();
		ll v = *it;
		nums.erase(it);

		it = nums.find(v * x);
		if (it == nums.end()) ++res;
		else nums.erase(it);
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