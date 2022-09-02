#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

constexpr ll modPow(ll a, ll b, ll c) {
	if ((b & 1) == 1) return a * modPow(a, b-1, c) % c;
	if (b == 0) return 1 % c;
	return modPow(a*a % c, b / 2, c);
}

// Applies the bit-reverse permutation to vec.
template<class T>
void bitReverse(vector<T>& vec) {
	int n = vec.size();
	int lg = 0;
	while((1<<lg) < n) ++lg;
	for (int i = 0; i < n; ++i) {
		int t = 0;
		for (int j = 0; j < lg; ++j) {
			if (i & (1<<j)) t |= 1<<(lg-1-j);
		}
		if (i < t) swap(vec[i], vec[t]);
	}
}

// Iterative FFT.
// Preconditions: P is prime, n = 2^lg for some lg, 2^lg | P-1, 3 is a generator of P, P < 2^30
// Time Complexity: O(n log(n))
template<int P>
void ntt(vector<int>& pol, bool inv) {
	bitReverse(pol); // Lets us calculate FFT iteratively

	int n = pol.size();
	int lg = 0;
	while((1<<lg) < n) ++lg;
	
	ll nth_root = modPow(3, (P-1)/n, P);
	if (inv) nth_root = modPow(nth_root, n-1, P);

	vector<ll> pows(lg, nth_root); // nth_root^(2^(lg-1-i))
	for (int i = lg-2; i >= 0; --i) pows[i] = (pows[i+1] * pows[i+1]) % P;

	ll tmp = 1;
	for (int i = 0; i < n; ++i) tmp = (tmp * nth_root) % P;	

	for (lg = 0; (1<<lg) < n; ++lg) {
		int h = 1<<lg;	// half
		int len = h<<1;	// step length
		ll root = pows[lg];
		for (int j = 0; j < n; j += len) {
			ll curr = 1;
			for (int i = j; i < j+h; ++i) {
				int tmp = (curr * pol[i + h]) % P;
				curr = (curr * root) % P;
				
				pol[i + h] = P - tmp + pol[i];
				if (pol[i + h] >= P) pol[i + h] -= P;
				
				pol[i] += tmp;
				if (pol[i] >= P) pol[i] -= P;
			}
		}
	}
}

// Calculates a * b = c (mod P) for two polynomials a and b. Assumes 0 <= a[i], b[i] < P.
// Time Complexity: O(n log n) where n = O(a.size() + b.size())
template<int P>
vector<int> polyMult(vector<int> a, vector<int> b) {
	int as = a.size();
	int bs = b.size();
	int n = 1;
	while(n < (as + bs)) n <<= 1;

	a.resize(n, 0);
	b.resize(n, 0);
	ntt<P>(a, false);
	ntt<P>(b, false);

	vector<int> c(n);
	int n_inv = modPow(n, P-2, P);
	for (int i = 0; i < n; ++i) {
		ll prod = (ll)a[i]*b[i] % P;
		c[i] = prod*n_inv % P;
	}

	ntt<P>(c, true);
	c.resize(as+bs-1);
	return c;
}

constexpr int MOD = 998244353;

vector<int> solve(int a, int b, const vector<int>& vec) {
	if (a == b) return {1, vec[a]};
	int ab = (a + b) >> 1;
	vector<int> le = solve(a, ab, vec);
	vector<int> ri = solve(ab+1, b, vec);
	vector<int> res = polyMult<MOD>(le, ri);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;

	vector<int> as(n);
	for (int i = 0; i < n; ++i) cin >> as[i];

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		vector<int> cp = as;
		int t;
		cin >> t;
		if (t == 1) {
			int q, i, d;
			cin >> q >> i >> d;
			cp[i-1] = d;
			for (int j = 0; j < n; ++j) {
				cp[j] = (q - cp[j]) % MOD;
				if (cp[j] < 0) cp[j] += MOD;
			}
		} else {
			int q, l, r, d;
			cin >> q >> l >> r >> d;
			for (int j = l-1; j < r; ++j) cp[j] = cp[j] + d;
			for (int j = 0; j < n; ++j) {
				cp[j] = (q - cp[j]) % MOD;
				if (cp[j] < 0) cp[j] += MOD;
			}
		}
		vector<int> res = solve(0, n-1, cp);
		if (res[k] < 0) res[k] += MOD;
		cout << res[k] << '\n';
	}
}