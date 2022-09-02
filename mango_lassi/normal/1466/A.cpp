#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> xs(n);
	for (int i = 0; i < n; ++i) {
		cin >> xs[i];
	}
	vector<int> offs;
	for (int a = 0; a < n; ++a) {
		for (int b = a+1; b < n; ++b) {
			ll val = abs(xs[b] - xs[a]);
			offs.push_back(val);
		}
	}
	sort(offs.begin(), offs.end());
	offs.erase(unique(offs.begin(), offs.end()), offs.end());
	cout << offs.size() << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}