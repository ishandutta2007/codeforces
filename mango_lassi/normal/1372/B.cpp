#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1e9;

void solve() {
	ll n;
	cin >> n;

	// If n is even, n/2 is optimal
	// If n is divisible by 3, n/3 and 2n/3 is optimal
	// p smallest prime divisor -> n(p-1)/p ??

	ll t = n; // >= 2
	for (ll d = 2; d*d <= n; ++d) {
		if (n % d == 0) {
			t = d;
			break;
		}
	}

	ll x = n / t;
	ll a = 1;
	ll b = t - 1;

	cout << a*x << ' ' << b*x << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		solve();
	}
}