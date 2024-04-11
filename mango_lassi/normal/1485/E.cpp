#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

const int N = 2 * (int)1e5;
vector<int> g[N];
int par[N];
ll as[N];
ll dp[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		--p;
		g[i].push_back(p);
		g[p].push_back(i);
	}

	as[0] = 0;
	for (int i = 1; i < n; ++i) cin >> as[i];

	// DP[r]: maximum points so far when the red coin is on r and we haven't placed the blue coin yet
	// DP[r] = max(
	//		DP[p] + max(|A[p] - min_A[dep[p]]|, |A[p] - max_A[dep[p]]), 
	//		DP[x] + |A[p] - A[x]|);

	par[0] = -1;
	vector<int> que = {0};
	while(true) {
		ll max_a = -INF, min_a = INF, max_off = -INF, min_off = INF;
		for (int i : que) {
			max_a = max(max_a, as[i]);
			min_a = min(min_a, as[i]);
			max_off = max(max_off, as[i] + dp[i]);
			min_off = min(min_off, as[i] - dp[i]);
		}

		vector<int> nxt;
		for (int i : que) {
			for (int j : g[i]) {
				if (j != par[i]) {
					nxt.push_back(j);
					par[j] = i;
				}
			}
		}
		if (nxt.empty()) {
			cout << max(max_off - min_a, max_a - min_off) << '\n';
			break;
		} else {
			que = nxt;

			for (int i : que) {
				dp[i] = dp[par[i]] + max(abs(as[par[i]] - max_a), abs(as[par[i]] - min_a));
				dp[i] = max(dp[i], max_off - as[par[i]]);
				dp[i] = max(dp[i], as[par[i]] - min_off);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		g[i].clear();
		g[i].shrink_to_fit();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}