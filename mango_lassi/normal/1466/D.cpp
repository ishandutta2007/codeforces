#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	ll sum = 0;
	vector<ll> vals(n);
	for (ll& v : vals) {
		cin >> v;
		sum += v;
	}

	vector<int> deg(n, 0);

	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		++deg[a];
		++deg[b];
	}

	priority_queue<ll> offs;
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < deg[i]; ++j) offs.push(vals[i]);
	}

	for (int k = 1; k <= n-1; ++k) {
		cout << sum << ' ';
		if (! offs.empty()) {
			sum += offs.top();
			offs.pop();
		}
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}