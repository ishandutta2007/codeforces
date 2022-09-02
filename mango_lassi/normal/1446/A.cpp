#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	ll w;
	cin >> n >> w;
	vector<pair<ll, int>> items(n);
	for (int i = 0; i < n; ++i) {
		cin >> items[i].first;
		items[i].second = i;
	}
	sort(items.begin(), items.end());
	reverse(items.begin(), items.end());

	ll val = w;
	vector<int> res;
	for (int i = 0; i < n; ++i) {
		if (items[i].first <= val) {
			res.push_back(items[i].second + 1);
			val -= items[i].first;
		}
	}

	if (2 * val > w) cout << -1 << '\n';
	else {
		cout << res.size() << '\n';
		for (auto v : res) cout << v << ' '; cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}