#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

ll modPow(ll a, ll b) {
	if ((b & 1) == 1) return a * modPow(a, b-1) % MOD;
	if (b == 0) return 1;
	return modPow(a*a % MOD, b / 2);
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
	
	ll nth_root = modPow(3, (P-1)/n);
	if (inv) nth_root = modPow(nth_root, n-1);

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
	int n_inv = modPow(n, P-2);
	for (int i = 0; i < n; ++i) {
		ll prod = (ll)a[i]*b[i] % P;
		c[i] = prod*n_inv % P;
	}

	ntt<P>(c, true);
	c.resize(as+bs-1);
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> vals(n);
	for (int i = 0; i < n; ++i) cin >> vals[i];
	sort(vals.begin(), vals.end());

	vector<int> counts = {1};
	for (int i = 1; i < n; ++i) {
		if (vals[i] == vals[i-1]) ++counts.back();
		else counts.push_back(1);
	}
	sort(counts.begin(), counts.end());
	int k = counts.size();

	priority_queue<pair<int, int>> que;
	vector<vector<int>> act(k);
	for (int i = 0; i < k; ++i) {
		act[i].resize(counts[i]+1, 1);
		que.push({-(counts[i] + 1), i});
	}
	while(que.size() > 1) {
		int x = que.top().second;
		que.pop();
		int y = que.top().second;
		que.pop();
		vector<int> comb = polyMult<MOD>(act[x], act[y]);

		act[x] = comb;
		act[y].clear();
		que.push({-(int)comb.size(), x});
	}

	int tar = 0;
	for (auto v : counts) tar += v;
	tar /= 2;
	
	cout << act[que.top().second][tar] << '\n';
}