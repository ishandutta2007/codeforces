#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int K = 14;

void mAdd(int& a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}
void mSub(int& a, int b) {
	a -= b;
	if (a < 0) a += MOD;
}
int mSum(int a, int b) {
	return (a+b >= MOD ? a+b - MOD : a+b);
}

int ways[K];

void solve() {
	long long m;
	cin >> m;

	// P(2) = a0 + 2a1 + 4a2 + ... + 2^{k} ak
	// DP with current carry term as state

	for (int i = 0; i < K; ++i) ways[i] = 0;
	ways[0] = 1;

	for (; m; m /= 2) {
		// Update counts
		for (int b = 1; b < K; ++b) mAdd(ways[b], ways[b-1]);
		for (int b = K-1; b >= 8; --b) mSub(ways[b], ways[b-8]);

		// Make sure we have / don't have the bit
		for (int i = 1 ^ (m & 1); i < K; i += 2) {
			ways[i] = 0;
		}

		// Divide remainder by two
		for (int b = 0; b < K/2; ++b) {
			ways[b] = mSum(ways[2*b], ways[2*b+1]);
		}
		for (int b = K/2; b < K; ++b) ways[b] = 0;
	}
	cout << ways[0] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}