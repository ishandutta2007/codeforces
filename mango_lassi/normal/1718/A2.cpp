#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// returns number of elements strictly smaller than v in vec
template<class T>
int bins(const vector<T>& vec, T v) {
	int low = 0;
	int high = vec.size();
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid] < v) low = mid + 1;
		else high = mid;
	}
	return low;
}

void solve() {
	int n;
	cin >> n;

	vector<ll> as(n + 1, 0ll);
	vector<pair<ll, int>> ord(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> as[i];
		as[i] ^= as[i-1];
		ord[i] = {as[i], i};
	}
	ord[0] = {0ll, 0};
	sort(ord.begin(), ord.end());

	vector<ll> dp(n + 1, 0ll);
	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1];
		int j = bins(ord, {as[i], i});
		if (j >= 0 && ord[j-1].first == as[i]) {
			int t = ord[j-1].second;
			dp[i] = max(dp[i], dp[t] + 1);
		}
	}
	cout << n - dp[n] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}