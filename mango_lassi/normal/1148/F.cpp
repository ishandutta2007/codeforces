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
template<class T>
T rand() {
	return uniform_int_distribution<T>()(rng);
}

const ll MX = (ll)1<<62;

const int N = 3 * (int)1e5;
int val[N];
ll mask[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> val[i] >> mask[i];
		sum += val[i];
	}
	ll s = 0;
	for (ll j = 1; j < MX; j <<= 1) {
		ll tmp = 0;
		for (int i = 0; i < n; ++i) {
			if ((mask[i] < 2*j) && (mask[i] & j)) {
				tmp += val[i] * (__builtin_popcountll(mask[i] & s) % 2 ? -1 : 1);
			}
		}

		if (tmp > 0 && sum > 0 || tmp < 0 && sum < 0) {
			s |= j;
		}
	}
	cout << s << '\n';
}