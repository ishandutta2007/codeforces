#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

// \sum_{S \subseteq T} gcd(S) (-1)^{|S| + 1}
// = \sum_{d = 1}^{n} \sum_{S \subseteq T} d (-1)^{|S| + 1} [gcd(S) == d]
// = \sum_{d = 1}^{n} d \sum_{S \subseteq T} (-1)^{|S| + 1} \sum_{k | gcd(S) / d} m(k)
// = \sum_{d = 1}^{n} \sum_{k = 1}^{n} d m(k) \sum_{S \subseteq T : dk | s \in S} (-1)^{|S| + 1}
// = \sum_{d = 1}^{n} \sum_{k = 1}^{n} d m(k) [dk | s \in S]
// = \sum_{v = 1}^{n} [v | s \in S] \sum_{d | v} d m(v/d)
// = \sum_{v = 1}^{n} [v | s \in S] \phi(v)

struct Sieve {
	vector<int> primes;  // primes[i]    := i+1'th prime
	vector<int> div_ind; // div_ind[x]   := minimum i s.t. primes[i] \divides x
	vector<int> totient; // totient[p^k] := p^k - p^{k-1}

	Sieve(int n) : div_ind(n+1, -1), totient(n+1, 1) {
		vector<int> base(n+1, 1);
		for (int i = 2; i <= n; ++i) {
			if (div_ind[i] == -1) {
				div_ind[i] = primes.size();
				primes.push_back(i);
			}
			for (int j = 0; j <= div_ind[i]; ++j) {
				int p = primes[j];
				int t = p * i;
				if (t > n) break;
				div_ind[t] = j;
				base[t] = (j == div_ind[i] ? base[i] : i);
			}

			// Calculate multiplicative functions
			int bs = base[i];
			if (bs == 1) {
				int p = primes[div_ind[i]];
				int j = i/p;
				totient[i] = totient[j] * (p - (i == p));
			} else {
				int pk = i/bs;
				totient[i] = totient[bs] * totient[pk];
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	Sieve sieve(n+1);
	vector<int> offs(n-2);
	for (int i = 0; i < n-2; ++i) offs[i] = sieve.totient[i+3];
	sort(offs.begin(), offs.end());

	ll res = 1 + (k > 1); // Points for 1 and 2
	for (int i = 0; i < k; ++i) res += offs[i];
	cout << res << '\n';
}