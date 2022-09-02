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
	for (int i = 1; i < n; ++i) {
		if (xs[i] <= xs[i-1]) ++xs[i];
	}
	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());
	cout << xs.size() << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}