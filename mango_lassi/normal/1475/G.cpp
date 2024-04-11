#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int H = 2 * (int)1e5;
int dp[H+1];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i <= H; ++i) dp[i] = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++dp[a];
	}

	for (int a = H; a >= 1; --a) {
		int add = 0;
		for (int x = 2*a; x <= H; x += a) add = max(add, dp[x]);
		dp[a] += add;
	}
	cout << n - dp[1] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}