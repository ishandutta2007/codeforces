#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

ll modPow(ll a, ll b) {
	if (b & 1) return (a * modPow(a, b - 1)) % MOD;
	if (b == 0) return 1;
	return modPow(a*a % MOD, b / 2);
}

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

// Tree
// Root at 0, think about setting v[0]
// Get the ratios g[i] = a[i] / b[i] = r[i] / r[1]. We must have that v[0] g[i] is an integer for every i
// Answer is v[0] * \sum g[i]
// Can maintain current g[i] as a prime count array
// Prime power in v[0] must be at least minimum value every position gets!

void updateCur(vector<int>& cur, vector<int>& maxv, int num, int mult, const vector<int>& primes, const vector<int>& div_ind) {
	while(num > 1) {
		int i = div_ind[num];
		num /= primes[i];

		cur[i] += mult;
		maxv[i] = max(maxv[i], cur[i]);
	}
}

ll dfs(int i, int p, ll v, vector<int>& cur, vector<int>& maxv, const vector<int>& primes, const vector<int>& div_ind, const vector<vector<pair<int, pair<int, int>>>>& g) {
	/*
	cerr << i << ": ";
	for (int j = 0; j < 6; ++j) {
		cerr << primes[j] << "=" << cur[j] << ' ';
	}
	cerr << '\n';
	*/

	ll res = v;
	for (auto pr : g[i]) {
		int t = pr.first;
		int x = pr.second.first, y = pr.second.second;
		if (t == p) continue;
		updateCur(cur, maxv, x, -1, primes, div_ind);
		updateCur(cur, maxv, y, 1, primes, div_ind);
		
		ll nxt_v = (v * x % MOD) * modPow(y, MOD - 2) % MOD;
		ll sub = dfs(t, i, nxt_v, cur, maxv, primes, div_ind, g);
		res = (res + sub) % MOD;

		updateCur(cur, maxv, y, -1, primes, div_ind);
		updateCur(cur, maxv, x, 1, primes, div_ind);
	}
	return res;
}

void solve() {
	int n;
	cin >> n;

	vector<int> primes, div_ind;
	tie(primes, div_ind) = sieve(n);
	
	int k = primes.size();
	vector<int> cur(k, 0), maxv(k, 0);

	vector<vector<pair<int, pair<int, int>>>> g(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		--a; --b;

		g[a].emplace_back(b, make_pair(y, x));
		g[b].emplace_back(a, make_pair(x, y));
	}

	ll mult = dfs(0, -1, 1, cur, maxv, primes, div_ind, g);
	ll base = 1;
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < maxv[i]; ++j) {
			base = (base * primes[i]) % MOD;
		}
	}
	cout << mult * base % MOD << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}