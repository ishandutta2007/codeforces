#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll P = 998244353;

constexpr ll modPow(ll a, ll b, ll c) {
	if ((b & 1) == 1) return a * modPow(a, b-1, c) % c;
	if (b == 0) return 1 % c;
	return modPow(a*a % c, b / 2, c);
}

// Applies the bit-reverse permutation to vec.
void bitReverse(vector<int>& vec) {
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
vector<int> polyMult(vector<int> a, vector<int> b) {
	int as = a.size();
	int bs = b.size();
	int n = 1;
	while(n < (as + bs)) n <<= 1;

	a.resize(n, 0);
	b.resize(n, 0);
	ntt(a, false);
	ntt(b, false);

	vector<int> c(n);
	int n_inv = modPow(n, P-2, P);
	for (int i = 0; i < n; ++i) {
		ll prod = (ll)a[i]*b[i] % P;
		c[i] = prod*n_inv % P;
	}

	ntt(c, true);
	c.resize(as+bs-1);
	return c;
}

const int N = 10 + 4 * (int)1e5;
ll fact[N];
ll inv_fact[N];
ll twop[N];

ll choose(int a, int b) {
	if (b > a) return 0;
	ll div = inv_fact[b] * inv_fact[a-b] % P;
	return fact[a] * div % P;
}

vector<int> build(const vector<ll>& as, ll h) {
	int n = as.size();
	int x = 0, y = 0;
	for (int i = 0; i < n && as[i] < h;) {
		int j = i;
		while(j < n && as[j] == as[i]) ++j;
		if (j-i == 1) ++x;
		else ++y;
		i = j;
	}
	n = x+2*y+1;

	vector<int> vec1(n, 0), vec2(n, 0);
	for (int i = 0; i < n; ++i) {
		vec1[i] = choose(2*y, i);
		vec2[i] = choose(x, i) * twop[i] % P;
	}
	vector<int> res = polyMult(vec1, vec2);
	while(res.back() == 0) res.pop_back();
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	fact[0] = 1;
	twop[0] = 1;
	inv_fact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = (i * fact[i-1]) % P;
		twop[i] = (2 * twop[i-1]) % P;
		inv_fact[i] = modPow(fact[i], P-2, P);
	}

	int n, k;
	cin >> n >> k;

	vector<ll> as(n), bs(k);
	for (int i = 0; i < n; ++i) cin >> as[i];
	for (int i = 0; i < k; ++i) cin >> bs[i];
	sort(as.begin(), as.end());

	vector<vector<int>> dp(k);
	for (int j = 0; j < k; ++j) dp[j] = build(as, bs[j]);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		int t;
		cin >> t;

		ll res = 0;
		for (int j = 0; j < k; ++j) {
			int c = (t/2) - bs[j] - 1;
			if (c >= 0 && c < dp[j].size()) {
				res += dp[j][c];
			}
		}
		cout << (res % P) << '\n';
	}
}