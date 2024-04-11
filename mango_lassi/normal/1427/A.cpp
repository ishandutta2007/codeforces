#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> as(n);
	for (int& v : as) cin >> v;
	sort(as.begin(), as.end());

	ll sum = 0;
	for (auto v : as) sum += v;
	if (sum == 0) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		if (sum > 0) reverse(as.begin(), as.end());
		for (auto v : as) cout << v << ' '; cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) solve();
	
}