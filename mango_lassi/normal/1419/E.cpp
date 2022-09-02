#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> buildDivs(int v) {
	vector<int> res;
	for (ll k = 1; k*k <= v; ++k) {
		if (v % k == 0) {
			res.push_back(k);
			if (v/k > k) res.push_back(v/k);
		}
	}
	return res;
}

void solve() {
	ll n;
	cin >> n;

	// Moves to decrypt = number of adjacent coprime values

	// Say it's divisible by p^2. Do the following:
	// ap a ap^2 bp b bp^2 ...
	// Where a, b, ... loop over what remains of the number.
	// -> 0 moves to decrypt

	// Say its divisible by p and q. Do the following:
	// ap a aq aqp bp b bq bqp ...
	// -> 0 moves to decrypt

	// -> Answer is 1 IFF the number is a product of exactly two primes, and 0 otherwise
	
	ll tmp = n;
	vector<pair<int, int>> factor;
	for (ll k = 2; k*k <= tmp; ++k) {
		if (tmp % k == 0) {
			int apps = 0;
			do {
				tmp /= k;
				++apps;
			} while (tmp % k == 0);

			factor.push_back({apps, k});
		}
	}
	if (tmp > 1) factor.push_back({1, tmp});

	sort(factor.begin(), factor.end());
	reverse(factor.begin(), factor.end());

	if (factor[0].first >= 2) {
		int p = factor[0].second;
		ll rem = n;
		while(rem % p == 0) rem /= p;
		vector<int> oths = buildDivs(rem);

		for (auto v : oths) {
			cout << p * v << ' ';
			if (v > 1) cout << v << ' ';

			ll cur = (ll)p*p;
			for (int ind = 2; ind <= factor[0].first; ++ind) {
				cout << cur * v << ' ';
				cur *= p;
			}
		}
		cout << '\n' << 0 << '\n';
	} else if (factor.size() >= 3) {
		ll p = factor[0].second;
		ll q = factor[1].second;
		ll r = factor[2].second;
		ll rem = n / (p*q*r);
		vector<int> oths = buildDivs(rem);
		
		for (auto v : oths) {
			cout << p*q	* v << ' ';
			cout << p	* v << ' ';
			cout << p*r	* v << ' ';
			cout << r	* v << ' ';
			cout << r*q	* v << ' ';
			cout << q	* v << ' ';
			if (v > 1) cout << v << ' ';
			cout << p*q*r	* v << ' ';
		}
		cout << '\n' << 0 << '\n';
	} else if (factor.size() == 2) {
		ll p = factor[0].second;
		ll q = factor[1].second;
		cout << p << ' ' << p*q << ' ' << q << '\n';
		cout << 1 << '\n';
	} else {
		cout << factor[0].second;
		cout << '\n' << 0 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}