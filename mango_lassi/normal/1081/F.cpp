#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int abs(int v) {
	return (v < 0 ? -v : v);
}

int flip(int l, int r) {
	cout << "? " << l+1 << ' ' << r+1 << endl;
	int res;
	cin >> res;
	return res;
}

// Flips prefix ending at i, i > 0, and returns number of ones afterwards.
int flipPrefix(int i, int n, int t) {
	bool flip_pref = false;
	bool flip_suff = false;
	int len = i+1;
	while((flip_pref == false) || (flip_suff == true)) {
		int nt = -1;
		if (n % 2 == 0) {
			nt = flip(i, i);
		} else {
			nt = flip(i-1, i);
		}
		
		int dp = abs(t - nt) % 2;
		if (dp == (len % 2)) {
			flip_pref ^= 1; // Flipped prefix
		} else {
			flip_suff ^= 1;
		}
		t = nt;
	}
	return t;
}

// Flips suffix starting at i, i < n-1, and returns number of ones afterwards.
int flipSuffix(int i, int n, int t) {
	bool flip_pref = false;
	bool flip_suff = false;
	int len = n-i;
	while((flip_pref == true) || (flip_suff == false)) {
		int nt = -1;
		if (n % 2 == 0) {
			nt = flip(i, i);
		} else {
			nt = flip(i, i+1);
		}
		
		int dp = abs(t - nt) % 2;
		if (dp == (len % 2)) {
			flip_suff ^= 1; // Flipped suffix
		} else {
			flip_pref ^= 1;
		}
		t = nt;
	}
	return t;
}

const int N = 300;
int ans[N];

void answer(int n) {
	cout << "! ";
	for (int i = 0; i < n; ++i) cout << ans[i];
	cout << endl;
}

int main() {
	int n, t;
	cin >> n >> t;

	if (n == 1) {
		ans[0] = t;
		answer(1);
	} else {
		for (int i = (n % 2); i < n; ++i) {
			int nt = flipPrefix(i, n, t);
			int dt = t - nt;
			int len = i+1;
			// pref-ones - pref_zeroes = dt
			// pref-ones + pref_zeroes = len
			// pref_ones = (dt + len) / 2;
			int pref_ones = (dt + len) / 2;
			ans[i] = pref_ones;
			flipPrefix(i, n, nt); // Return back
		}

		// Find first number in odd case
		if (n % 2 == 1) {
			int nt = flipSuffix(1, n, t);
			int dt = t - nt;
			int len = n-1;
			int suff_ones = (dt + len) / 2;
			ans[0] = t - suff_ones;
			flipSuffix(1, n, t); // Return back
		}
		for (int i = n-1; i > 0; --i) ans[i] -= ans[i-1];
		answer(n);
	}
}