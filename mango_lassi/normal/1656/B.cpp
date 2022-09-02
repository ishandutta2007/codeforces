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
	ll k;
	cin >> n >> k;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;
	sort(as.begin(), as.end());

	// Operation on x, then on y
	// Outcome: z <- (z - x) - (y - x) = z - y
	// -> Only last operation matters
	// -> Are there two integers the subtraction of which equals k

	bool works = 0;
	for (ll v : as) {
		int j = bins(as, k + v);
		if (j < n && as[j] == k + v) works = 1;
	}
	if (works) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}