#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const ll INF0 = 1e9;
const ll INF1 = 1e18;

ll getMX(ll max_add, ll a) {
	ll mx = max_add + a - 1;
	if (mx < 0) return -1;
	else return mx / 3;
}

// Finds maximum x such that x^2 + x <= v
ll getMaxX(ll v) {
	if (v < 0) return -1;
	ll low = 0;
	ll high = 2 * INF0;
	while(low != high) {
		ll mid = (low + high + 1) >> 1;
		if (mid * (mid + 1) > v) high = mid - 1;
		else low = mid;
	}
	return low;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// maximise \sum b_i(a_i - b_i^2) subject to
	// 1. \sum b_i = k
	// 2. b_i <= a_i

	int n;
	ll k;
	cin >> n >> k;

	vector<ll> as(n);
	for (ll& v : as) cin >> v;

	// Minimise b_i^3 - a_i b_i
	// The cost functions are convex, thus we can greedily up the b_i's.
	// Binary search how much we add by increasing b_i
	//	(X+1)^3 = X^3 + 3X^2 + 3X + 1

	ll low = -INF0;
	ll high = 4 * INF1;
	while(low != high) {
		ll mid = (low + high) >> 1;
		ll cou = 0;
		for (int i = 0; i < n; ++i) {
			// Maximum integer x such that 3x^2 + 3x + 1 - as[i] <= mid
			// -> x^2 + x <= (mid + as[i] - 1) / 3 (division rounds down, not towards zero)
			ll mx = getMX(mid, as[i]);
			ll max_x = min(as[i], getMaxX(mx) + 1); // Can have at most this many
			cou += max_x;
		}
		if (cou >= k) high = mid;
		else low = mid + 1;
	}

	ll cou = -k;
	for (int i = 0; i < n; ++i) {
		ll mx = getMX(low, as[i]);
		ll max_x = min(as[i], getMaxX(mx) + 1); // Can have at most this many
		cou += max_x;
	}
	
	for (int i = 0; i < n; ++i) {
		ll mx = getMX(low, as[i]);
		ll tmp = getMaxX(mx);

		if (cou > 0 && 0 <= tmp && tmp < as[i] && 3 * tmp * (tmp + 1) + 1 - as[i] == low) {
			// Reduce by one more
			--cou;
			cout << tmp << ' ';
		} else {
			ll b = min(as[i], tmp + 1);
			cout << b << ' ';
		}
	}
	cout << '\n';
}