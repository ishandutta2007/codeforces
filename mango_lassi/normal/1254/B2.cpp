#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using ll = long long;
const ll INF = 4 * (ll)1e18;

const int N = 1e6;

tuple<vector<int>, vector<int>> sieve(int n) {
	vector<int> primes;
	vector<int> div_ind(n+1, -1);
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

ll solve(vector<ll> as, ll d) {
	ll res = 0;
	ll cur = 0;
	int i = 0;
	while(i < as.size()) {
		if (as[i] == 0) {
			if (cur != 0) res += min(cur, d - cur);
			++i;
		} else {
			ll add = min(d - cur, as[i]);
			as[i] -= add;
			cur += add;

			if (cur == d) {
				as[i] %= d;
				cur = 0;
			}
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> primes, div_ind;
	tie(primes, div_ind) = sieve(N);

	int n;
	cin >> n;

	ll sum = 0;
	vector<ll> as(n);
	for (int i = 0; i < n; ++i) {
		cin >> as[i];
		sum += as[i];
	}

	ll res = INF;
	for (auto p : primes) {
		if (sum % p == 0) {
			do {
				sum /= p;
			} while (sum % p == 0);

			ll off = solve(as, p);
			res = min(res, off);
		}
	}
	if (sum > 1) res = min(res, solve(as, sum));

	if (res < INF) cout << res << '\n';
	else cout << -1 << '\n';
}