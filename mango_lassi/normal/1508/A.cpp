#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int n;
		cin >> n;

		string str[3];
		cin >> str[0] >> str[1] >> str[2];
		
		int ind[3];
		ind[0] = 0; ind[1] = 0; ind[2] = 0;
		
		string res;
		for (int i = 0; i < 3*n; ++i) {
			// First full after k operations
			// -> larger of others has at least (2k - 2n) / 2
			// -> <= k + 2n - (2k - 2n) / 2 operations
			// -> <= 3n operations
			
			int zc = 0, oc = 0;
			int max_zc = -1, max_oc = -1;
			for (int j = 0; j < 3; ++j) {
				if (ind[j] < 2*n) {
					if (str[j][ind[j]] == '0') {
						++zc;
						max_zc = max(max_zc, ind[j]);
					} else {
						++oc;
						max_oc = max(max_oc, ind[j]);
					}
				}
			}

			bool pick_zero = (zc > oc || (zc == oc && max_zc > max_oc));
			if (pick_zero) res.push_back('0');
			else res.push_back('1');

			for (int j = 0; j < 3; ++j) {
				if (ind[j] < 2*n) {
					if ((str[j][ind[j]] == '0') == pick_zero) ++ind[j];
				}
			}
		}
		cout << res << '\n';
	}
}