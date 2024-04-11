#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int MOD = (int)1e9 + 7;

ll modPow(ll a, ll b) {
	if (b & 1) return a * modPow(a, b ^ 1) % MOD;
	if (b == 0) return 1;
	return modPow(a*a % MOD, b >> 1);
}

void solve() {
	int n;
	ll p;
	cin >> n >> p;
	
	vector<ll> ks(n);
	for (ll& k : ks) cin >> k;
	sort(ks.begin(), ks.end());
	reverse(ks.begin(), ks.end());

	// greedy division works
	ll diff = 0, cap_diff = 0;
	ll cur = ks[0];
	for (auto k : ks) {
		// Update current power
		if (cap_diff != 0 && p != 1) {
			diff = (diff * modPow(p, cur - k)) % MOD;
			for (int i = k; (i < cur) && (cap_diff < n); ++i) {
				cap_diff *= p;
			}
		}
		cur = k;

		if (cap_diff > 0) {
			// Add to second week
			--diff;
			--cap_diff;
		} else {
			// Add to first week
			++diff;
			++cap_diff;
		}
	}
	diff = (diff * modPow(p, cur)) % MOD;
	
	diff %= MOD;
	if (diff < 0) diff += MOD;
	cout << diff << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}