#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

// rand-function that works properly on windows, and is faster than rand
// https://codeforces.com/blog/entry/61587
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rand(T a, T b) {
	return uniform_int_distribution<T>(a, b)(rng);
}

const int K = 40;
const int N = 2 * (int)1e5;
ll vals[N];

ll solve(ll t, int n) {
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		if (vals[i] < t) res += t - vals[i];
		else {
			ll m1 = vals[i] % t;
			ll m2 = t - m1;
			if (m2 >= t) m2 -= t;
			res += min(m1, m2);
		}
	}
	return res;
}

vector<ll> factor(ll v) {
	vector<ll> res;
	for (ll x = 2; x*x <= v; ++x) {
		if (v % x == 0) {
			res.push_back(x);
			while(v % x == 0) v /= x;
		}
	}
	if (v > 1) res.push_back(v);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Number of operations is at most n
	// Pick random number, the divisor divides some number at most 1 away from it with probability at least 1/2

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> vals[i];

	ll res = n;
	for (int j = 0; j < K; ++j) {
		int i = rand(0, n-1);
		for (ll t = vals[i]-1; t <= vals[i]+1; ++t) {
			auto vec = factor(t);
			for (ll p : vec) res = min(res, solve(p, n));
		}
	}
	cout << res << '\n';
}