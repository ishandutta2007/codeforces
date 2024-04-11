#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 3000;
vector<int> conns[N];

vector<pair<int, ll>> dp[N];

int siz[N];
ll as[N];
ll bs[N];

void solve(int i, int p) {
	siz[i] = 1;
	dp[i] = {{0, bs[i] - as[i]}};
	for (auto t : conns[i]) {
		if (t == p) continue;
		solve(t, i);
	
		// Close child
		dp[t].push_back({-1, 0});
		for (int j = siz[t] - 1; j >= 0; --j) {
			dp[t][j+1] = max(dp[t][j+1], {dp[t][j].first + (dp[t][j].second > 0), 0});
		}

		// Combine in time left * right
		dp[i].resize(siz[i] + siz[t]);
		for (int s = siz[i] + siz[t] - 1; s >= 0; --s) {
			pair<int, ll> off = {-N, 0};
			for (int a = min(s, siz[i] - 1); a >= max(0, s - siz[t]); --a) {
				int b = s - a;
				pair<int, ll> can = {dp[i][a].first + dp[t][b].first, dp[i][a].second + dp[t][b].second};
				off = max(off, can);
			}
			dp[i][s] = off;
		}
		siz[i] += siz[t];
		dp[t].clear();
		dp[t].shrink_to_fit();
	}
}

void solve() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i) cin >> as[i];
	for (int i = 0; i < n; ++i) cin >> bs[i];

	for (int i = 0; i < n; ++i) conns[i].clear();
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}

	solve(0, 0);
	cout << dp[0][k-1].first + (dp[0][k-1].second > 0) << '\n';
	dp[0].clear();
	dp[0].shrink_to_fit();

	// combine in left * right
	// Claim: at most n^2 work
	// Proof: when combining two of sizes a and b, we do a^2 + b^2 + ab work, which is <= (a+b)^2

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}