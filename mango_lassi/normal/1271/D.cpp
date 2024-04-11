#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1e18;

const int N = 5000;
const int K = 5000;
int as[N];
int bs[N];
int cs[N];

int mx[N];
vector<ll> offs[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	int s = k;
	for (int i = 0; i < n; ++i) {
		cin >> as[i] >> bs[i] >> cs[i];
		mx[i] = i;
		s += bs[i];
	}
	for (int j = 0; j < m; ++j) {
		int a, b;
		cin >> a >> b;
		mx[b-1] = max(mx[b-1], a-1);
	}
	for (int i = 0; i < n; ++i) {
		offs[mx[i]].push_back(cs[i]);
		sort(offs[i].begin(), offs[i].end());
		reverse(offs[i].begin(), offs[i].end());
	}

	vector<ll> dp(s+1, -INF);
	dp[k] = 0;
	for (int i = 0; i < n; ++i) {
		// Conquer
		for (int j = 0; j < as[i]; ++j) dp[j] = -INF;

		// Recruit
		for (int j = s - bs[i]; j >= 0; --j) dp[j + bs[i]] = max(dp[j + bs[i]], dp[j]);

		// Defend
		for (int j = 0; j <= s; ++j) {
			ll sum = 0;
			for (int t = 1; t <= offs[i].size() && j-t >= 0; ++t) {
				sum += offs[i][t-1];
				dp[j-t] = max(dp[j-t], dp[j] + sum);
			}
		}
	}
	ll res = -1;
	for (auto v : dp) res = max(res, v);
	cout << res << '\n';
}