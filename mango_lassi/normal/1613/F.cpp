#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

constexpr ll mAdd(ll a, ll b, ll c) {
	return (a+b >= c ? a+b-c : a+b);
}
constexpr ll mSub(ll a, ll b, ll c) {
	return (a < b ? a-b+c : a-b);
}
constexpr ll modPow(ll a, ll b, ll c) {
	return ((b & 1) ? (a * modPow(a, b ^ 1, c) % c) : (b == 0) ? 1 : (modPow(a*a % c, b >> 1, c)));
}

// Iterative NTT in O(n log n)
// Preconditions: P is prime, n = 2^m, 2^m | P-1, 3 is a generator of P
template<int P>
void ntt(vector<int>& vec, bool inv) {
	// Apply the bit-reverse permutation
	int n = vec.size();
	for (int i = 0; i < n; ++i) {
		int t = 0;
		for (int j = 0; (1<<j) < n; ++j) {
			if (i & (1<<j)) t |= n >> (j+1);
		}
		if (i < t) swap(vec[i], vec[t]);
	}
	// Do Cooley-Tukey
	int root = modPow(3, (inv ? (n-1) : 1) * (ll)(P-1) / n, P);
	for (int h = 1; h < n; h <<= 1) {
		ll curr = 1, mult = modPow(root, n / (2*h), P);
		for (int j = 0; j < h; ++j) {
			for (int i = j; i < n; i += 2*h) {
				ll v = (curr * vec[i^h]) % P;
				vec[i^h] = mSub(vec[i], v, P);
				vec[i] = mAdd(vec[i], v, P);
			}
			curr = (curr * mult) % P;
		}
	}
}

// Calculates a * b = c (mod P) for two polynomials a and b. P must be valid for ntt. Assumes 0 <= a[i], b[i] < P.
template<int P>
vector<int> polyMult(vector<int> a, vector<int> b) {
	int n = 1, t = (int)a.size() + b.size() - 1;
	while(n < t) n <<= 1;

	a.resize(n, 0); b.resize(n, 0);
	ntt<P>(a, 0); ntt<P>(b, 0);

	vector<int> c(n);
	int n_inv = modPow(n, P-2, P);
	for (int i = 0; i < n; ++i) c[i] = (ll)a[i]*b[i] % P * n_inv % P;

	ntt<P>(c, 1);
	c.resize(t);
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> deg(n, -1);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		++deg[a - 1];
		++deg[b - 1];
	}
	++deg[0];

	int h = 1;
	while(h < n) h <<= 1;
	vector<vector<int>> pols(h, vector<int>(1, 1));
	for (int i = 0; i < n; ++i) pols[i] = {deg[i], 1};

	for (h >>= 1; h > 0; h >>= 1) {
		for (int i = 0; i < h; ++i) pols[i] = polyMult<MOD>(pols[i], pols[i + h]);
	}

	ll res = 0, fact = 1;
	for (int i = 0; i <= n; ++i) {
		ll term = (fact * pols[0][i]) % MOD;
		if ((n - i) & 1) res = mSub(res, term, MOD);
		else res = mAdd(res, term, MOD);
		fact = (fact * (i + 1)) % MOD;
	}
	cout << res << '\n';
}