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

// Struct for priority queue operations on index set [0, n-1]
// push(i, v) overwrites value at position i if one already exists
// decKey is faster but requires that the new key is smaller than the old one
struct Prique {
	const ll INF = 4 * (ll)1e18;
	vector<pair<ll, int>> data;
	const int n;

	Prique(int siz) : n(siz), data(2*siz, {INF, -1}) { data[0] = {-INF, -1}; }
	pair<ll, int> top() const { return data[1]; }
	void push(int i, ll v) {
		data[i+n] = {v, (v >= INF ? -1 : i)};
		for (i += n; i > 1; i >>= 1) data[i>>1] = min(data[i], data[i^1]);
	}
};

void solve(const vector<int>& primes) {
	int n, q;
	cin >> n >> q;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;

	vector<ll> vals;
	vector<int> divs;

	int m = 1;
	divs.push_back(1);
	for (int j = 0; j < primes.size() && primes[j] < n; ++j) {
		int d = primes[j];
		if (n % d == 0) {
			divs.push_back(n / d);
			m += n / d;
		}
	}
	vals.resize(m, 0ll);

	for (int i = 0; i < n; ++i) {
		int cur = 0;
		for (int d : divs) {
			vals[cur + i % d] -= (ll)d * as[i];
			cur += d;
		}
	}

	Prique pq(m);
	for (int i = 0; i < m; ++i) pq.push(i, vals[i]);
	cout << -pq.top().first << '\n';
	
	for (int j = 0; j < q; ++j) {
		int i;
		ll v;
		cin >> i >> v;
		--i;

		ll diff = v - as[i];
		as[i] = v;
		
		int cur = 0;
		for (int d : divs) {
			int ind = (cur + i % d);
			vals[ind] -= (ll)d * diff;
			pq.push(ind, vals[ind]);
			cur += d;
		}
		cout << -pq.top().first << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	const int N = 2 * (int)1e5;
	auto prec = sieve(N);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve(prec.first);
}