#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;
const ll INF = 1e10;

ll dp[(1 << 16)][256];
ll sr, sb;
ll r[20];
ll b[20];
char cl[20];
int n;


int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> cl[i];
		cin >> r[i] >> b[i];
		sr += r[i];
		sb += b[i];
	}
	for (int i = 0; i < 256; ++i) {
		dp[0][i] = -INF;
	}
	dp[0][0] = 0;
	for (int i = 1; i < (1 << n); ++i) {
		for (int j = 0; j < 256; ++j)
			dp[i][j] = -INF;
		ll cr = 0;
		ll cb = 0;
		for (int j = 0; j < n; ++j)
			if ((i >> j) & 1) {
				if (cl[j] == 'R')
					++cr;
				else
					++cb;
			}
		for (int j = 0; j < 256; ++j) {
			for (int k = 0; k < n; ++k) {
				if ((i >> k) & 1) {
					if (cl[k] == 'R') {
						if (j < min(r[k], cr - 1))
							continue;
						dp[i][j] = max(dp[i][j], dp[i ^ (1 << k)][j - min(r[k], cr - 1)] + min(b[k], cb));
					}
					else {
						if (j < min(r[k], cr))
							continue;
						dp[i][j] = max(dp[i][j], dp[i ^ (1 << k)][j - min(r[k], cr)] + min(b[k], cb - 1));
					}
				}
			}
		}
	}
	ll ans = INF;
	for (int i = 0; i < 256; ++i) {
		ans = min(ans, max(sr - i, sb - dp[(1 << n) - 1][i]));
	}
	cout << ans + n << "\n";
	return 0;
}