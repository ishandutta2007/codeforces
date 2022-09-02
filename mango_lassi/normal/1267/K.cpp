#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 20;
ll fact[N+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// If we don't sort the multiset, the integer is unique
	// Hence the answer is the number of permutations where pi <= i for all i
	// Except that the last pi must be nonzero.

	fact[0] = 1;
	for (int i = 1; i <= N; ++i) fact[i] = fact[i-1] * i;

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		ll k;
		cin >> k;
		vector<int> vals;
		for (int j = 2; k > 0; ++j) {
			vals.push_back(k % j);
			k /= j;
		}
		sort(vals.begin(), vals.end());

		ll res = 1;
		for (int j = 1; j <= vals.size(); ++j) {
			int cou = -(j-1);
			for (auto v : vals) {
				if (v <= j) ++cou;
			}
			res *= cou;
		}
		// Subtract configurations with zero in final position
		ll sub = 0;
		for (auto v : vals) sub += (v == 0);
		for (int j = 1; j < vals.size(); ++j) {
			int cou = -j;
			for (auto v : vals) {
				if (v <= j) ++cou;
			}
			sub *= cou;
		}
		res -= sub;
		
		int cur = 1;
		for (int i = 1; i <= vals.size(); ++i) {
			if (i == vals.size() || vals[i] != vals[i-1]) {
				res /= fact[cur];
				cur = 1;
			} else ++cur;
		}
		--res;


		cout << res << '\n';
	}
}