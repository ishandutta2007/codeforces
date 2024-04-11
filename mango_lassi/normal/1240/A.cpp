#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void solve() {
	int n;
	cin >> n;
	vector<ll> vals(n);
	for (int i = 0; i < n; ++i) cin >> vals[i];
	sort(vals.begin(), vals.end());

	ll x, a;
	cin >> x >> a;
	ll y, b;
	cin >> y >> b;
	ll gab = (a * b) / gcd(a, b);
	
	ll k;
	cin >> k;

	int low = 0;
	int high = n+1;
	while(low != high) {
		int mid = (low + high) >> 1;
		ll c_both = mid / gab;
		ll c_a = mid / a - c_both;
		ll c_b = mid / b - c_both;
		ll sum = 0;
		for (int i = n-1; i >= n - mid; --i) {
			if (c_both == 0 && c_a == 0 && c_b == 0) break;
			if (c_both > 0) {
				sum += vals[i] * (x + y) / 100;
				--c_both;
			} else if ((c_a > 0 && x > y) || c_b == 0) {
				sum += vals[i] * x / 100;
				--c_a;
			} else {
				sum += vals[i] * y / 100;
				--c_b;
			}
		}
		if (sum >= k) high = mid;
		else low = mid + 1;
	}
	if (low == n+1) {
		cout << -1 << '\n';
	} else {
		cout << low << '\n';
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) solve();

}