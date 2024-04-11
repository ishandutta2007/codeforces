#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rand(T a, T b) {
	return uniform_int_distribution<T>(a, b)(rng);
}
template<class T>
T rand() {
	return uniform_int_distribution<T>()(rng);
}
*/

const ll MAX_M = (ll)1e14;
const int MAX_OPS = 105;

/*
const ll H0 = 1e3;
const ll H1 = 1e6;
const ll H2 = 1e10;
*/

// ll test_m;
int ops = 0;

bool ask(ll v) {
	++ops;

	cout << "? " << v << endl;
	
	string ans;
	cin >> ans;
	return (ans[0] == 'L');

	// return v <= test_m;
}

void solve() {
	// Guess r of your money, unless that puts you over the midpoint of the possible interval
	// Start with large ratio, then decrease it over time

	ll low = 0;
	ll high = MAX_M;

	// Once you have range H, 2H
	// You can in two operations, add H, then add (H + 2H) / 2

	// r^2 = 1 - r
	// cost below = 3, cost above = 1
	// 

	// C(n) = max(3 + C(n * r), 1 + C(n * (1 - r)))
	// C(n) = c log n

	// c log n + max(3 + c log r, 1 + c log (1 - r))
	
	ll cur = 1;
	while(low != high) {
		ll mx = max(1ll, cur - 1);
		ll mid = low + (high - low) * ((cur >= high * (MAX_OPS - ops)) ? 0.5 : (cur >= 5 * high ? 1 - 0.6 : 1 - 0.7)); // 
		mx = min(mx, mid + 1);
		mx = max(mx, low);

		if (ask(mx)) {
			cur += mx;
			low = max(low, mx);
		} else {
			cur -= mx;
			high = min(high, mx - 1);
		}
	}
	cout << "! " << low << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		/*
		if (rand(0, 3) == 0) {
			test_m = rand(0ll, MAX_M);
		} else if (rand(0, 2) == 0) {
			test_m = rand(0ll, H0);
		} else if (rand(0, 1) == 0) {
			test_m = rand(0ll, H1);
		} else {
			test_m = rand(0ll, H2);
		}
		*/
		
		solve();

		// cerr << test_m << ' ' << ops << '\n';
		// if (ops >= MAX_OPS) break;
		ops = 0;
	}
}