#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
const int C = 26;
int dp[C][C];
int tmp[C][C];

void solve() {
	string str;
	cin >> str;
	for (int c = 0; c < C; ++c) {
		for (int c2 = 0; c2 < C; ++c2) dp[c][c2] = 0;
	}

	for (auto c : str) {
		for (int c2 = 0; c2 < C; ++c2) {
			for (int c1 = 0; c1 < C; ++c1) tmp[c2][c1] = INF;
			pair<int, int> best[2] = {{-1, INF}, {-1, INF}};
			for (int c1 = 0; c1 < C; ++c1) {
				pair<int, int> off = {c1, dp[c1][c2]};
				if (best[0].second > off.second) swap(best[0], off);
				if (best[1].second > off.second) swap(best[1], off);
			}
			for (int tc = 0; tc < C; ++tc) {
				if (tc == c2) continue;
				int cost = (tc == (c - 'a') ? 0 : 1);

				if (tc == best[0].first) {
					tmp[c2][tc] = min(tmp[c2][tc], best[1].second + cost);
				} else {
					tmp[c2][tc] = min(tmp[c2][tc], best[0].second + cost);
				}
			}
		}
		for (int c1 = 0; c1 < C; ++c1) {
			for (int c2 = 0; c2 < C; ++c2) {
				dp[c1][c2] = tmp[c1][c2];
			}
		}
	}

	int res = INF;
	for (int c = 0; c < C; ++c) {
		for (int c2 = 0; c2 < C; ++c2) res = min(res, dp[c][c2]);
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}