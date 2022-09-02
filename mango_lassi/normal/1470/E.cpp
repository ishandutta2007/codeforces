#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3 * (int)1e4;
const int C = 4;
ll cou[N+1][C+1];
ll below[2][N+1][C+1];

bool answer(ll v) {
	cout << v << '\n';
	return true;
}

void solve() {
	int n, c, q;
	cin >> n >> c >> q;

	vector<int> perm(n);
	for (int& p : perm) cin >> p;

	for (int h = 0; h <= c; ++h) {
		below[0][0][h] = 0;
		below[1][0][h] = 0;
	}
	for (int k = 1; k <= n; ++k) {
		vector<pair<int, int>> ord(min(k, c + 1));
		for (int i = 0; i < ord.size(); ++i) ord[i] = {perm[n-k + i], i};
		sort(ord.begin(), ord.end());

		for (int h = 0; h <= c; ++h) {
			below[0][k][h] = below[0][k-1][h];
			below[1][k][h] = below[1][k-1][h];

			ll cur = 0;
			for (int t = 0; t < ord.size(); ++t) {
				if (ord[t].second > h) continue;
				if (ord[t].second == 0) below[0][k][h] += cur;
				else cur += cou[k-1-ord[t].second][h - ord[t].second];
			}
			cur = 0;
			for (int t = (int)ord.size() - 1; t >= 0; --t) {
				if (ord[t].second > h) continue;
				if (ord[t].second == 0) below[1][k][h] += cur;
				else cur += cou[k-1-ord[t].second][h - ord[t].second];
			}
		}
	}

	for (int qi = 0; qi < q; ++qi) {
		int j;
		ll k;
		cin >> j >> k;
		j = n + 1 - j; // Number left when we answer

		if (k > cou[n][c]) {
			cout << -1 << '\n';
			continue;
		}

		// cerr << "Query " << j << ' ' << k << ": " << endl;

		// jth number in permutation with k below it
		int r = n, h = c, s = 0;
		bool ans = 0;
		while(! ans) {
			if (h == 0) {
				ans = answer(perm[n-j]);
				break;
			}

			if (below[s][r][h] + 1 < k) {
				k = cou[r][h] + 1 - k;
				s ^= 1;
			}
			//cerr << r << ' ' << h << ' ' << s << ": " << k << ' ' << j << ": " << below[s][r][h] << endl;

			if (below[s][r][h] >= k) {
				// Go down!
				int low = 0;
				int high = r;
				while(low != high) {
					int mid = (low + high) >> 1;
					if (k <= below[s][r][h] - below[s][mid][h]) {
						low = mid + 1;
					} else {
						high = mid;
					}
				}

				//cerr << below[s][3][h] << ' ' << below[s][2][h] << ' ' << below[s][1][h] << endl;

				//cerr << "bins: " << low << ' ' << below[s][r][h] << ' ' << below[s][low][h] << endl;
				// Apply operation at low
				if (low < j) {
					ans = answer(perm[n-j]);
				} else {
					k -= below[s][r][h] - below[s][low][h];

					vector<pair<int, int>> ord(min(low, h + 1));
					for (int i = 0; i < ord.size(); ++i) ord[i] = {perm[n-low + i], i};
					sort(ord.begin(), ord.end());
					if (s == 1) reverse(ord.begin(), ord.end());

					for (int t = 0; t < ord.size() && !ans; ++t) {
						int dh = ord[t].second;
						ll add = cou[low - dh - 1][h - dh];
						if (add >= k) {
							assert(dh > 0);
							if (low - dh - 1 < j) {
								ans = answer(perm[n - (low - (j - (low - dh)))]);
							} else {
								r = low - dh - 1;
								h -= dh;
								break;
							}
						} else {
							k -= add;
						}
					}
				}
			} else {
				ans = answer(perm[n-j]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int c = 0; c <= 4; ++c) cou[0][c] = 1;
	for (int n = 1; n <= N; ++n) {
		for (int c = 0; c <= 4; ++c) {
			for (int r = 0; r <= min(c, n - 1); ++r) {
				cou[n][c] += cou[n-1-r][c-r];
			}
		}
	}

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}