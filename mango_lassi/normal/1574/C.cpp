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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	ll sum = 0;
	vector<ll> as(n);
	for (ll& a : as) {
		cin >> a;
		sum += a;
	}
	sort(as.begin(), as.end());

	int m;
	cin >> m;

	for (int i = 0; i < m; ++i) {
		ll x, y;
		cin >> x >> y;

		int j = bins(as, x);
		ll ans = x + y;
		if (j < n) ans = min(ans, max(0ll, y - (sum - as[j])));
		if (j > 0) ans = min(ans, (x - as[j - 1]) + max(0ll, y - (sum - as[j - 1])));
		cout << ans << '\n';
	}

}