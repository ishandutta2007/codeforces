#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <array>
#include <random>
#include <chrono>
using namespace std;
using ll = long long;
 
// rand-function that works properly on windows, and is faster than rand
// https://codeforces.com/blog/entry/61587
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rand(T a, T b) {
	return uniform_int_distribution<T>(a, b)(rng);
}
 
// Counts subsets with sum between a and b in O(n sqrt(2)^n)
int mitm(vector<ll> vals, ll a, ll b) {
	if (vals.size() & 1) vals.push_back(0);
	int n = (int)vals.size() / 2;
	int m = 1 << n;
	vector<ll> le(m), ri(m);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i & (1<<j)) {
				le[i] += vals[j];
				ri[i] += vals[j+n];
			}
		}
	}
	sort(le.begin(), le.end());
	sort(ri.begin(), ri.end());
 
	int x = m-1;
	int y = m-1;
	int res = 0;
	for (int i = 0; i < m; ++i) {
		while(x >= 0 && le[i] + ri[x] > b) --x;
		while(y >= 0 && le[i] + ri[y] >= a) --y;
		res += x - y;
	}
	return res;
}
 
template<int N>
class BinaryConv {
	private:
		static constexpr int M = 1 << N;
		array<bitset<M>, N> has_bit;
		
		void mob(bitset<M>& f) {
			for (int b = 0; b < N; ++b) {
				f ^= has_bit[b] & (f << (1 << b));
			}
		}
		array<bitset<M>, N+1> tMob(const bitset<M>& f) {
			array<bitset<M>, N+1> res;
			for (int m = 0; m < M; ++m) res[__builtin_popcount(m)][m] = f[m];
			for (int n = 0; n <= N; ++n) mob(res[n]);
			return res;
		}
	public:
		BinaryConv() {
			for (int m = 0; m < M; ++m) {
				for (int j = 0; j < N; ++j) has_bit[j][m] = (m & (1<<j));
			}
		}
		// res[m]: \xor_{s \subset m} f[s] & g[m^s]
		// Time complexity: O(n 2^n), space O(2^n)
		bitset<M> apply(const bitset<M>& f, const bitset<M>& g) {
			auto fc = tMob(f), gc = tMob(g);
			array<bitset<M>, N+1> tmp;
			for (int s = 0; s <= N; ++s) {
				for (int j = 0; j <= s; ++j) tmp[s] ^= fc[j] & gc[s-j];
				mob(tmp[s]);
			}
			bitset<M> res;
			for (int m = 0; m < M; ++m) res[m] = tmp[__builtin_popcount(m)][m];
			return res;
		}
};
 
const int N = 20;
const int M = 1<<N;
ll vals[N];
array<bitset<M>, N+1> works;
BinaryConv<N> conv;
 
void fix(bitset<M>& bt) {
	for (int i = 0; i < M; ++i) {
		if (bt[i]) {
			for (int j = 0; j < N; ++j) bt[i | (1<<j)] = 1;
		}
	}
}
 
// Randomized binary or-convolution in O(kn 2^n)
// A result bit that should be 1 is 0 with probability at most 2^-k
// If k = n, no bit is incorrect with probability at least 1/e ~ 0.367
bitset<M> randOrConv(const bitset<M>& le, const bitset<M>& ri, int k) {
	bitset<M> res, tmp = ri;
	for (; k; --k) {
		for (int i = 0; i < M; ++i) tmp[i] = (ri[i] && rand(0, 1));
		res |= conv.apply(le, tmp);
	}
	fix(res);
	return res;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 
	int n;
	cin >> n;
 
	int m = 1 << n;
	for (int i = 0; i < n; ++i) cin >> vals[i];
 
	// Find working subsets in O((1 + sqrt(2))^n)
	for (int i = 1; i < m; ++i) {
		ll sum = 0;
		vector<ll> act;
		for (int j = 0; j < n; ++j) {
			if (i & (1<<j)) {
				act.push_back(2 * vals[j]);
				sum += vals[j];
			}
		}
 
		int cou = __builtin_popcount(i);
		if ((sum + cou) & 1) {
			int tot = mitm(act, sum - (cou-1), sum + (cou-1));
			if (abs(sum) <= cou - 1) tot -= 2;
			if (tot) works[1][i] = 1;
		}
	}
	fix(works[1]);
 
	int res = n;
	if (works[1][m-1]) {
		// Randomised bit-zeta convolution for set packing in O(2^n * nk * log n)
		// Succeeds with probability at least (1 - 2^-k)^(n - 1) >= 0.98 when k = 10
		// A tighter upper bound exists for sure, especially when the answer is large

		int k = 1;
		for (; 2*k <= n; k *= 2) {
			works[2*k] = randOrConv(works[k], works[k], 10);
			if (! works[2*k][m-1]) break;
		}

		// k is now last power of two that works
		int t = k;
		for (k /= 2; k > 0; k /= 2) {
			if (t + k > n) continue;
			works[t + k] = randOrConv(works[t], works[k], 10);
			if (works[t + k][m-1]) t += k;
		}
		res -= t;
	}
	cout << res << '\n';
}