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

// Returns list of primes that divide v, every prime appearing once
vector<ll> factor(ll v, const vector<int>& primes) {
	vector<ll> res;
	for (int j = 0; j < primes.size() && (ll)primes[j]*primes[j] <= v; ++j) {
		if (v % primes[j] == 0) {
			res.push_back(primes[j]);
			while(v % primes[j] == 0) v /= primes[j];
		}
	}
	if (v > 1) res.push_back(v);
	return res;
}

void solve(const vector<int>& primes) {
	ll n;
	cin >> n;

	vector<ll> ps = factor(n, primes);
	pair<int, ll> res = {1, n};
	for (ll p : ps) {
		int k = 0;
		ll tmp = n;
		while(tmp % p == 0) {
			tmp /= p;
			++k;
		}
		pair<int, ll> off = {k, p};
		res = max(res, off);
	}

	cout << res.first << '\n';
	for (int i = 0; i + 1 < res.first; ++i) {
		cout << res.second << ' ';
		n /= res.second;
	}
	cout << n << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	const int H = 1e5;
	vector<int> primes = sieve(H+1).first;

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve(primes);
}