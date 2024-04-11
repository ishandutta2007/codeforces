#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = (ll)1e9 + 7;
const int H = 30;
const int N = 2 * (int)1e5;
ll two_pow[N + 1];

ll mSub(ll a, ll b) {
	return (a >= b ? a - b : a + MOD - b);
}
ll mAdd(ll a, ll b) {
	return (a + b >= MOD ? a + b - MOD : a + b);
}

void solve() {
	int n;
	cin >> n;
	
	// Arith sequence starting at x of length a has sum
	//	ax + a * (a-1) / 2 = ax + b
	// Thus, the GCD of a's in the subsequence has to divide the sum of b's in the subsequence

	// If a is odd, then a divides b
	// Otherwise, a divides 2b
	// Thus, we only need to check that the lowest power of two in a's is either 2^0 or occurs an even number of times

	vector<int> count(H, 0);
	for (int i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		int lg = 0;
		for (; a % 2 == 0; a >>= 1) ++lg;
		++count[lg];
	}
	
	int rem = n - count[0];
	ll res = mSub(two_pow[n], two_pow[rem]); // Ones where we have a odd number
	for (int c = 1; c < H; ++c) {
		// Ones where we take a even nonzero number of lengths with this log
		// Ways to take even amount from k
		// = (1 + 1)^k / 2 + (1 - 1)^k / 2 = 2^{k-1}
		if (count[c] == 0) continue;
		rem -= count[c];
		res = (res + mSub(two_pow[count[c] - 1], 1) * two_pow[rem]) % MOD;
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	two_pow[0] = 1;
	for (int i = 1; i <= N; ++i) two_pow[i] = 2 * two_pow[i-1] % MOD;

	int t = 1;
	// cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}