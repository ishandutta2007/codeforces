#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> as(n), bs(n), cs(n);
	for (int& v : as) cin >> v;
	for (int& v : bs) cin >> v;
	for (int& v : cs) cin >> v;

	int first = -1;
	int prev = -1;
	for (int i = 0; i < n; ++i) {
		int v;
		if (prev == as[i] || first == as[i]) {
			if (prev == bs[i] || first == bs[i]) {
				v = cs[i];
			} else {
				v = bs[i];
			}
		} else {
			v = as[i];
		}
		cout << v << ' ';
		prev = v;
		if (i == 0) first = v;
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