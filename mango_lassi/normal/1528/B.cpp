#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

// Struct for precalculation of multiplicative functions
struct Sieve {
	vector<int> primes;  // primes[i]    := i+1'th prime
	vector<int> div_ind; // div_ind[x]   := minimum i s.t. primes[i] | x
	vector<int> div_cou; // div_cou[p^k] := k+1

	Sieve(int n) : div_ind(n+1, -1), div_cou(n+1, 1) {
		vector<int> base(n+1, 1);
		for (int i = 2; i <= n; ++i) {
			if (div_ind[i] == -1) {
				div_ind[i] = primes.size();
				primes.push_back(i);
			}
			for (int j = 0; j <= div_ind[i]; ++j) {
				int t = i * primes[j];
				if (t > n) break;
				div_ind[t] = j;
				base[t] = (j == div_ind[i] ? base[i] : i);
			}

			// Calculate multiplicative functions
			int bs = base[i];
			if (bs == 1) {
				int p = primes[div_ind[i]];
				int j = i/p;
				div_cou[i] = div_cou[j] + 1;
			} else {
				int pk = i/bs;
				div_cou[i] = div_cou[bs] * div_cou[pk];
			}
		}
	}
};

const int N = (ll)1e6 + 10;
ll dp[N];
ll sums[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	Sieve sv(n);

	// 2n points
	// All same length: div_cou(n)
	// Not all same length: shorther ones must be covered by all -> \sum_{0 < k < n} DP[k]

	for (int i = 1; i <= n; ++i) {
		dp[i] = (sv.div_cou[i] + sums[i-1]) % MOD;
		sums[i] = (sums[i-1] + dp[i]) % MOD;
	}
	cout << dp[n] << '\n';
}