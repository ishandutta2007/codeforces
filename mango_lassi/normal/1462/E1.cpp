#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	int m = 3, k = 2;

	vector<int> as(n);
	for (int& a : as) cin >> a;
	sort(as.begin(), as.end());

	int y = 0;
	ll res = 0;
	for (int x = 0; x < n; ++x) {
		while(y < n && as[y] - as[x] <= k) ++y;
		ll len = y-x;
		if (len >= m) res += (len-1) * (len - 2) / 2;
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