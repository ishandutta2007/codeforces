#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1e18;

const int K = 9;
const int N = 1<<K;
pair<ll, int> pri[N]; // Minimum price of this mask
int dp[N][K+1]; // Sum of cou over masks with any of the k first bits turned zero from one

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < N; ++i) {
		pri[i] = {INF, -1};
	}
	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;
		int mask = 0;
		for (int j = 0; j < c; ++j) {
			int z;
			cin >> z;
			mask |= 1<<(z-1);
		}
		++dp[mask][0];
	}

	vector<pair<ll, int>> offs(m);
	for (int i = 0; i < m; ++i) {
		int cost, c;
		cin >> cost >> c;
		int mask = 0;
		for (int j = 0; j < c; ++j) {
			int z;
			cin >> z;
			mask |= 1<<(z-1);
		}
		pri[mask] = min(pri[mask], {cost, i+1});
		offs[i] = {cost, i+1};
	}
	sort(offs.begin(), offs.end());

	for (int k = 1; k <= K; ++k) {
		int b = 1<<(k-1);
		for (int i = 0; i < N; ++i) {
			dp[i][k] = dp[i][k-1];
			if (i & b) dp[i][k] += dp[i ^ b][k-1];
		}
	}

	int ans_cou = -1;
	ll ans_pri = INF;
	int ans_1 = -1;
	int ans_2 = -1;
	for (int a = 0; a < N; ++a) {
		for (int b = 0; b < N; ++b) {
			ll off_pri;
			int off_1, off_2;
			if (a == b) {
				off_pri = pri[a].first;
				off_1 = pri[a].second;
				if (off_1 != offs[0].second) {
					off_pri += offs[0].first;
					off_2 = offs[0].second;
				} else {
					off_pri += offs[1].first;
					off_2 = offs[1].second;
				}
			} else {
				off_pri = pri[a].first + pri[b].first;
				off_1 = pri[a].second;
				off_2 = pri[b].second;
			}
			if (off_pri >= INF) continue;

			int off_cou = dp[a | b][K];
			if (off_cou > ans_cou || (off_cou == ans_cou && off_pri <= ans_pri)) {
				ans_cou = off_cou;
				ans_pri = off_pri;
				ans_1 = off_1;
				ans_2 = off_2;
			}
		}
	}
	cout << ans_1 << ' ' << ans_2 << '\n';
}