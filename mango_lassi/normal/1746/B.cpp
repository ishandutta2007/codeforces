#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	int zc = 0, oc = 0;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		zc += (arr[i] == 0);
	}

	int res = n-1;
	for (int i = 0; i <= n; ++i) {
		int off = max(zc, oc);
		res = min(res, off);
		if (i == n) break;

		if (arr[i] == 0) --zc;
		if (arr[i] == 1) ++oc;
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