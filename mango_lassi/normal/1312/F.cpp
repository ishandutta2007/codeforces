#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int T = 3;
const int H = 5;
const int K = 100;
int dp[H][H][H][K][T];
pair<int, int> pr[H][H][H];

int grundy(int x, int y, int z, ll a, int t) {
	if (a >= K) {
		a -= pr[x][y][z].first;
		a %= pr[x][y][z].second;
		a += pr[x][y][z].first;
	}
	return dp[x][y][z][a][t];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int x = 0; x < 5; ++x) {
		for (int y = 0; y < 5; ++y) {
			for (int z = 0; z < 5; ++z) {
				for (int t = 0; t < 3; ++t) dp[x][y][z][0][t] = 0;
				for (int k = 1; k < K; ++k) {
					for (int t = 0; t < 3; ++t) {
						int can = 0;
						can |= 1 << dp[x][y][z][max(0, k-x-1)][0];
						if (t != 1) can |= 1 << dp[x][y][z][max(0, k-y-1)][1];
						if (t != 2) can |= 1 << dp[x][y][z][max(0, k-z-1)][2];

						for (int j = 0;; ++j) {
							if (! (can & (1 << j))) {
								dp[x][y][z][k][t] = j;
								break;
							}
						}
					}
				}
				pr[x][y][z] = {-1, -1};
				for (int a = 0; (a + H <= K) && pr[x][y][z].first == -1; ++a) {
					for (int b = a+1; (b + H <= K) && pr[x][y][z].first == -1; ++b) {
						bool fail = false;
						for (int k = 0; k < H; ++k) {
							for (int t = 0; t < 3; ++t) {
								if (dp[x][y][z][a+k][t] != dp[x][y][z][b+k][t]) fail = true;
							}
						}
						if (! fail) pr[x][y][z] = {a, b-a};
					}
				}
			}
		}
	}

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int n, x, y, z;
		cin >> n >> x >> y >> z;
		--x; --y; --z;

		int grd = 0;
		vector<ll> as(n);
		for (ll& v : as) {
			cin >> v;
			grd ^= grundy(x, y, z, v, 0);
		}
		int res = 0;
		for (ll& v : as) {
			int tar = grd ^ grundy(x, y, z, v, 0);
			if (tar == grundy(x, y, z, max(0ll, v - x-1), 0)) ++res;
			if (tar == grundy(x, y, z, max(0ll, v - y-1), 1)) ++res;
			if (tar == grundy(x, y, z, max(0ll, v - z-1), 2)) ++res;
		}
		cout << res << '\n';
	}
}