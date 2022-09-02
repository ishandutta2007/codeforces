#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

// d = 0: Last <= element
// d = 1: First >= element
template<class T>
int bins(const vector<T>& vec, T v, int d) {
	int low = -(d ^ 1);
	int high = (int)vec.size() - (d ^ 1);
	while(low < high) {
		int mid = (low + high + (d ^ 1)) >> 1;
		if (d == 0) {
			if (vec[mid] <= v) low = mid;
			else high = mid - 1;
		} else {
			if (vec[mid] >= v) high = mid;
			else low = mid + 1;
		}
	}
	return low;
}

const int N = 5000;
ll fact[N+1];
ll inv_fact[N+1];

ll modPow(ll a, ll b) {
	if (b & 1) return a * modPow(a, b ^ 1) % MOD;
	if (b == 0) return 1;
	return modPow(a*a % MOD, b >> 1);
}

ll binom(int a, int b) {
	if (b > a || b < 0) return -1;
	ll dv = inv_fact[b] * inv_fact[a-b] % MOD;
	return dv * fact[a] % MOD;
}

ll dp[N+1];

void solve() {
	int n;
	cin >> n;
	++n;

	vector<int> as(n, 0);
	for (int i = 1; i < n; ++i) cin >> as[i];
	sort(as.begin(), as.end());

	// Fail if 2 as[n-2] > as[n-1], as these two work in neither order
	if (2*as[n-2] > as[n-1]) {
		cout << 0 << '\n';
		return;
	}

	// If we know the sequence of maximums v_1 < ... < v_k (2v_i <= v_{i+1}), we can easily count the contribution to the answer:
	//	Let there be x_i values t such that t is not in the sequence of maximums, and v_{i-1} < 2t <= v_i. Let y_i = \sum_{j < i} x_i
	// 	Then the contribution is \prod_{i = 1}^{k} x_{i}! (n - i - y_i choose x_i)
	dp[n-1] = 1;
	for (int i = n-2; i >= 0; --i) {
		for (int j = i+1; j < n; ++j) {
			if (2*as[i] > as[j]) continue;

			// Get set of t with as[i] < 2*t <= as[j], t != as[i]
			int ia = bins(as, as[i] / 2 + 1, 1);
			int ib = bins(as, as[j] / 2, 0);

			int cou = ib - ia + (i == 0); // Remove as[i]
			int rem = n - ia - 1 - (i != 0);
			ll mult = (fact[cou] * binom(rem, cou)) % MOD;

			dp[i] = (dp[i] + mult * dp[j]) % MOD;
		}
	}
	cout << dp[0] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	fact[0] = 1;
	for (int i = 1; i <= N; ++i) fact[i] = (fact[i-1] * i) % MOD;
	inv_fact[N] = modPow(fact[N], MOD - 2);
	for (int i = N-1; i >= 0; --i) inv_fact[i] = (inv_fact[i+1] * (i+1)) % MOD;

	solve();
}