#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int count(vector<int> vals) {
	sort(vals.begin(), vals.end());
	int n = vals.size();
	int k = n / 4;

	int res = 0;
	for (int i = k; i < n; ++i) res += vals[i];
	return res;
}

void solve() {
	int n;
	cin >> n;

	vector<int> as(n), bs(n);
	for (int i = 0; i < n; ++i) cin >> as[i];
	for (int i = 0; i < n; ++i) cin >> bs[i];

	int low = 0;
	int high = n + 110;
	while(low != high) {
		int mid = (low + high) >> 1;
		as.resize(n + mid, 100);
		bs.resize(n + mid, 0);

		if (count(as) >= count(bs)) high = mid;
		else low = mid + 1;
	}
	cout << low << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}