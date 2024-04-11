#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = (ll)1e17;

const int N = 150;
const int M = 10;

// DP[a][b][c]: minimum number x, such that b * f(x) + c * f(x+1) = a
ll dp[N+1][M][M];

ll buildDP(int a, int b, int c) {
	// cerr << "buildDP(" << a << ' ' << b << ' ' << c << ")\n";

	// Base cases
	if (a < c) return INF; // target sum too small
	if ((a % 2 != b % 2) && (a % 2 != c % 2)) return INF; // wrong parity
	if (a == 0 && c == 0) return 0;

	if (dp[a][b][c] != -1) return dp[a][b][c];

	// Loop least significant digit
	ll res = INF;
	for (int d = (c == 0); d < M; ++d) {
		ll sum = d * b + (d < 9 ? d+1 : 0) * c;
		int add = (d < 9 ? c : 0);
		ll off = buildDP(a - sum, b + add, c - add);
		res = min(res, 10*off + d);
	}

	dp[a][b][c] = res;
	return res;
}

void solve() {
	int n, k;
	cin >> n >> k;

	ll res = INF;
	for (int d = 0; d < M; ++d) {
		int c = 0;
		ll sum = 0;
		for (int j = 0; j <= k; ++j) {
			sum += ((d+j) % 10);
			c += (d+j >= 10);
		}
		int b = k+1 - c;

		ll off = buildDP(n - sum, b, c);
		res = min(res, 10*off + d);
	}
	if (res >= INF) cout << -1 << '\n';
	else cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int a = 0; a <= N; ++a) {
		for (int b = 0; b < M; ++b) {
			for (int c = 0; c < M; ++c) dp[a][b][c] = -1;
		}
	}

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}