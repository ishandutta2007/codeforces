#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 200;
vector<int> vals[3];
ll dp[N+1][N+1][N+1];

void aMax(ll& a, ll b) {
	a = max(a, b);
}

void solve() {
	vector<int> ns(3);
	cin >> ns[0] >> ns[1] >> ns[2];

	// Exists order where we only take remaining maximum of some two piles at each step

	for (int j = 0; j < 3; ++j) {
		vals[j].resize(ns[j]);
		for (int i = 0; i < ns[j]; ++i) cin >> vals[j][i];
		sort(vals[j].begin(), vals[j].end());
		reverse(vals[j].begin(), vals[j].end());
	}
	for (int a = 0; a <= ns[0]; ++a) {
		for (int b = 0; b <= ns[1]; ++b) {
			for (int c = 0; c <= ns[2]; ++c) {
				dp[a][b][c] = 0;
			}
		}
	}

	ll res = 0;
	for (int a = 0; a <= ns[0]; ++a) {
		for (int b = 0; b <= ns[1]; ++b) {
			for (int c = 0; c <= ns[2]; ++c) {
				ll base = dp[a][b][c];
				if (a < ns[0] && b < ns[1]) aMax(dp[a+1][b+1][c], base + vals[0][a] * vals[1][b]);
				if (a < ns[0] && c < ns[2]) aMax(dp[a+1][b][c+1], base + vals[0][a] * vals[2][c]);
				if (b < ns[1] && c < ns[2]) aMax(dp[a][b+1][c+1], base + vals[1][b] * vals[2][c]);
				aMax(res, base);
			}
		}
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}