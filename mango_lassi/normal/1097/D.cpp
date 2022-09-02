#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

const int N = 64;
const int K = 1e4;
ll dp[K+1][N+1];
ll divs[N+1];

ll modPow(ll a, ll b){
	if (b & 1) return (a * modPow(a, b-1)) % MOD;
	if (b == 0) return 1;
	return modPow((a*a)%MOD, b / 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i <= N; ++i) divs[i] = modPow(i+1, MOD-2);

	// This expected value is multiplicative!
	// Calculate separately for every prime divisor
	ll n;
	int k;
	cin >> n >> k;

	vector<pair<ll, int>> pps; // Prime powers
	for (ll v = 2; v*v <= n; ++v) {
		if (n % v == 0) {
			int cou = 0;
			while(true) {
				n /= v;
				++cou;
				if (n % v != 0) break;
			}
			pps.push_back({v, cou});
		}
	}
	if (n > 1) pps.push_back({n, 1});

	ll res = 1;
	for (auto pr : pps) {
		ll p = pr.first;
		int cou = pr.second;
		
		dp[0][0] = 1;
		for (int i = 1; i <= cou; ++i) {
			dp[0][i] = (dp[0][i-1] * p) % MOD;
		}

		for (int j = 1; j <= k; ++j) {
			ll sum = 0;
			for (int i = 0; i <= cou; ++i) {
				sum = (sum + dp[j-1][i]) % MOD;
				dp[j][i] = (sum * divs[i]) % MOD;
			}
		}

		res = (res * dp[k][cou]) % MOD;
	}
	cout << res << '\n';
}