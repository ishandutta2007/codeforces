#include <bits/stdc++.h>
using namespace std;

void solve() {
	int k; 
	cin >> k;
	vector<int> a(7);
	for (int i = 0; i < 7; ++i) cin >> a[i];
	auto calc = [&](int x) {
		if (x < 0) return 0;
		int ans = (x / 7) * accumulate(a.begin(), a.end(), 0);
		x %= 7;
		for (int i = 0; i <= x; ++i) ans += a[i];
		return ans;
	};
	auto check = [&](int mid) {
		for (int i = 0; i < 7; ++i) {
			if (calc(i + mid - 1) - calc(i - 1) >= k) return true;
		}
		return false;
	};
	int low = 1, high = 1e9;
	while (low < high) {
		int mid = (low + high) >> 1;
		if (check(mid)) high = mid;
		else low = mid + 1;
	}
	cout << low << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	int tt; cin >> tt;
	while (tt--) {
		solve();
	}
}