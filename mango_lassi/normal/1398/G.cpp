#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;

const int MOD = 998244353;

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

const int H = 1e6;
int res[H+1];

void solve() {
	int n, x, y;
	cin >> n >> x >> y;

	// 2(y + as[i] - as[j]) divides t
	// Easy to solve if we can check for every value v, if there exists i, j for which as[i] - as[j] = v
	// This is also necessary, as we must know if we should answer "h" on query "h".

	// This can be done with FFT/NTT.
	vector<int> vec1(x+1, 0), vec2(x+1, 0);
	for (int i = 0; i <= n; ++i) {
		int a;
		cin >> a;
		vec1[a] = 1;
		vec2[x-a] = 1;
	}
	vector<int> prod = polyMult<MOD>(vec1, vec2);
	for (int i = x-1; i >= 0; --i) {
		if (prod[i] > 0) {
			int t = 2*(y + (x-i));
			if (t <= H) res[t] = t;
		}
	}

	// Answer queries
	for (int a = 1; a <= H; ++a) {
		for (int b = 2*a; b <= H; b += a) res[b] = max(res[b], res[a]);
	}
	
	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		int h;
		cin >> h;
		if (res[h] > 0) cout << res[h] << ' ';
		else cout << -1 << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}