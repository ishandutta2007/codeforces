#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

int n;
int r;
int f[1200];
int s[1200];
ld p[1200];
ld dp[100][5100];

const ld INF = 5e9;

int main() {
	cin >> n >> r;
	for (int i = 0; i < n; ++i) {
		cin >> f[i] >> s[i] >> p[i];
		p[i] /= 100;
	}
	ld lb = 0;
	ld rb = INF;
	for (int it = 0; it < 100; ++it) {
		ld mid = (lb + rb) / 2;
		for (int i = n - 1; i > 0; --i) {
			for (int j = 0; j <= r; ++j) {
				dp[i][j] = mid;
				if (j >= s[i]) {
					dp[i][j] = min(dp[i][j], p[i] * (f[i] + dp[i + 1][j - f[i]]) + (1 - p[i]) * (s[i] + dp[i + 1][j - s[i]]));
				}
				else if (j >= f[i]) {
					dp[i][j] = min(dp[i][j], p[i] * (f[i] + dp[i + 1][j - f[i]]) + (1 - p[i]) * (s[i] + mid));
				}
			}
		}
		ld go = 0;
		if (r >= s[0]) {
			go = p[0] * (f[0] + dp[0 + 1][r - f[0]]) + (1 - p[0]) * (s[0] + dp[0 + 1][r - s[0]]);
		}
		else {
			go = p[0] * (f[0] + dp[0 + 1][r - f[0]]) + (1 - p[0]) * (s[0] + mid);
		}
		if (go > mid)
			lb = mid;
		else
			rb = mid;
	}
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << (lb + rb) / 2 << "\n";
	return 0;
}