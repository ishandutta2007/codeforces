#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function for precalculating primes and prime divisors
pair<vector<int>, vector<int>> sieve(int n) {
	vector<int> div_ind(n+1, -1), primes;
	for (int i = 2; i <= n; ++i) {
		if (div_ind[i] == -1) {
			div_ind[i] = primes.size();
			primes.push_back(i);
		}
		for (int j = 0; j <= div_ind[i]; ++j) {
			int t = primes[j] * i;
			if (t > n) break;
			div_ind[t] = j;
		}
	}
	return {primes, div_ind};
}

void solve(const vector<int>& primes, const vector<int>& div_ind) {
	int k, n;
	cin >> n >> k;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;
	
	ll res = 0;
	vector<int> nxt(n + 1, 0), nxt2(n + 1, 0);
	for (int j = 0; j < k; ++j) {
		for (int i = j; i < n; i += k) {
			if (as[i] > 1) {
				if (as[i] == primes[div_ind[as[i]]]) {
					nxt[i] = 0;
					nxt2[i] = 1 + (i - k >= 0 ? nxt[i - k] : 0);
				} else {
					nxt[i] = 0;
					nxt2[i] = 0;
				}
			} else {
				nxt[i] = 1 + (i - k >= 0 ? nxt[i - k] : 0);
				nxt2[i] = 1 + (i - k >= 0 ? nxt2[i - k] : 0);
			}
			int add = max(0, nxt2[i] - max(1, nxt[i]));
			res += add;
		}
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	const int A = 1e6;
	vector<int> primes, div_ind;
	tie(primes, div_ind) = sieve(A);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve(primes, div_ind);
}