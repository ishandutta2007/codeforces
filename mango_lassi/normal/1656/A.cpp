#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> as(n);
	for (int& a : as) cin >> a;

	int i = 0, j = 0;
	for (int x = 1; x < n; ++x) {
		if (as[x] < as[i]) i = x;
		if (as[x] > as[j]) j = x;
	}
	cout << i + 1 << ' ' << j + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}