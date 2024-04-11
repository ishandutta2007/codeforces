#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

typedef long long int64;
typedef long double ld;

template <class T> bool bmin(T& a, T b) { return a > b ? (a = b, true) : false; }
template <class T> bool bmax(T& a, T b) { return a < b ? (a = b, true) : false; }

const int64 INF64 = 1e18;
const int INF = 1e9;

using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	vector <int> p(n);
	vector <char> used(n + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		used[p[i]] = 1;
	}

	int even = 0, odd = 0;
	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			if (i & 1) {
				odd++;
			} else {
				even++;
			}
		}
	}

	vector <vector <vector <pair <int, int>>>> dp(n, vector <vector <pair <int, int>>>(even + 1, vector <pair <int, int>>(odd + 1, { INF, INF })));
	if (p[0] != 0) {
		if (p[0] % 2 == 0) {
			dp[0][0][0].first = 0;
		} else {
			dp[0][0][0].second = 0;
		}
	} else {
		if (even != 0) {
			dp[0][1][0].first = 0;
		}
		if (odd != 0) {
			dp[0][0][1].second = 0;
		}
	}

	for (int i = 1; i < n; i++) {
		if (p[i] != 0) {
			for (int e = 0; e <= even; e++) {
				for (int o = 0; o <= odd; o++) {
					if (p[i] % 2 == 0) {
						if (dp[i - 1][e][o].first != INF) {
							dp[i][e][o].first = min(dp[i][e][o].first, dp[i - 1][e][o].first);
						}
						if (dp[i - 1][e][o].second != INF) {
							dp[i][e][o].first = min(dp[i][e][o].first, dp[i - 1][e][o].second + 1);
						}
					} else {
						if (dp[i - 1][e][o].first != INF) {
							dp[i][e][o].second = min(dp[i][e][o].second, dp[i - 1][e][o].first + 1);
						}
						if (dp[i - 1][e][o].second != INF) {
							dp[i][e][o].second = min(dp[i][e][o].second, dp[i - 1][e][o].second);
						}
					}
				}
			}
		} else {
			for (int e = 0; e <= even; e++) {
				for (int o = 0; o <= odd; o++) {
					if (e - 1 >= 0) {
						if (dp[i - 1][e - 1][o].first != INF) {
							dp[i][e][o].first = min(dp[i][e][o].first, dp[i - 1][e - 1][o].first);
						}
						if (dp[i - 1][e - 1][o].second != INF) {
							dp[i][e][o].first = min(dp[i][e][o].first, dp[i - 1][e - 1][o].second + 1);
						}
					}
					if (o - 1 >= 0) {
						if (dp[i - 1][e][o - 1].first != INF) {
							dp[i][e][o].second = min(dp[i][e][o].second, dp[i - 1][e][o - 1].first + 1);
						}
						if (dp[i - 1][e][o - 1].second != INF) {
							dp[i][e][o].second = min(dp[i][e][o].second, dp[i - 1][e][o - 1].second);
						}
					}
				}
			}
		}
	}

	cout << min(dp[n - 1][even][odd].first, dp[n - 1][even][odd].second) << '\n';
}