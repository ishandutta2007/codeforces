#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2 * (int)1e5;
const int H = 20;
int cou[N+1 + 1000];
int sum[N+1 + 1000];
int dp[N+1 + 1000][H];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, max_a;
	cin >> n >> max_a;

	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		cou[a] ^= 1;
	}
	for (int i = 1; i <= max_a + 1; ++i) sum[i] = sum[i-1] ^ cou[i-1];
	
	// Store counts
	// bit 1 is set IFF among positions 1, 3, 5, ... we have a odd amount
	// bit 2 is set IFF among positions 2, 3, 6, 7, ... we have a odd amount
	// In dp[i][h], store sum of positions [i, i + 1 * 2^h) + [i + 2 * 2^h, i + 3 * 2^h) + ...

	// for (int i = 0; i <= max_a; ++i) cerr << sum[i] << ' '; cerr << '\n';

	for (int h = 0; h < H; ++h) {
		int a = 1 << h;
		if (a > max_a) break;
		for (int i = max_a; i >= 0; --i) {
			dp[i][h] = (i + 2*a <= max_a ? dp[i + 2*a][h] : 0) ^ (sum[min(max_a + 1, i + a)] ^ sum[i]);
		}
		// for (int i = 0; i <= max_a; ++i) cerr << dp[i][h]; cerr << '\n';
	}

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		int le, ri;
		cin >> le >> ri;
		int len = ri - le + 1;
		
		bool nonzero = 0;
		for (int h = 0; h < H; ++h) {
			int a = (1 << h);
			int k = len >> h;
			if (le + a > max_a) break;

			int bit = dp[le + a][h];
			if (k & 1) {
				int f = le + a * k;
				if (f <= max_a) {
					bit ^= dp[f][h];
					bit ^= sum[ri+1] ^ sum[f];
				}
			} else {
				int f = le + a * (k+1);
				if (f <= max_a) bit ^= dp[f][h];
			}
			// cerr << bit;
			if (bit != 0) nonzero = 1;
		}
		// cerr << ' ';

		cout << "BA"[nonzero];

		// cerr << '\n';
	}
	cout << '\n';
}