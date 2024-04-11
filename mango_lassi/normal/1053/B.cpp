#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 3 * (int)1e5;
const int M = 100;
int cou[N];
ll pref[N + 1];

int popc(ull v) {
	int res = 0;
	ull b = 1;
	while(b <= v) {
		if (v & b) ++res;
		b <<= 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ll v;
		cin >> v;
		cou[i] = popc(v);
	}

	pref[0] = 0;
	for (int i = 0; i < n; ++i) {
		pref[i+1] = pref[i] + cou[i];
	}

	// Interval (a, b) is good, if sum(a, b) is even, and max(a, b) <= 2 * sum(a, b)
	// max <= 64, therefore all intervals of length > 64 are good, iff their sum is even.

	// a1 a2 a3 ... ak-1 ak
	
	// Lemma: possible with all ints of length 3, such that sum is even, and sum >= 2 * max.
	// Proof: can subtract one from two integers.

	ll res = 0;
	for (int a = 0; a < n; ++a) {
		ll sum = 0;
		int mx = 0;
		// Handle intervals [a, b] with amount of integers <= M
		for (int b = a; b < min(n, a + M); ++b) {
			sum += cou[b];
			mx = max(mx, cou[b]);
			if ((sum % 2 == 0) && (2 * mx <= sum)) ++res;
		}
	}

	int evens = 0;
	int odds = 0;
	for (int b = 0; b < n; ++b) {
		if (cou[b] % 2 != 0) swap(evens, odds);
		if (b >= M) {
			// Handle intervals [a, b] with length > M
			int a = b - M;
			if ((pref[b+1] - pref[a]) % 2 != 0) ++odds;
			else ++evens;
		}
		res += evens;
	}

	cout << res << '\n';
}