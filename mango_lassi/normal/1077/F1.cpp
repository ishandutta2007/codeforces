#include <iostream>
#include <deque>
#include <utility>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

const int N = 5000;
ll val[N];
ll dp[N+1][N+1];

int main() {
	// If k is small, trivial
	// If k is large, 
	int n, k, x;
	cin >> n >> k >> x;
	for (int i = 0; i < n; ++i) cin >> val[i];	

	for (int i = 0; i <= n; ++i) dp[i][0] = -INF;
	dp[0][0] = 0;

	for (int s = 1; s <= x; ++s) {
		deque<pair<ll, int>> que;
		que.push_back({0, 0});
		for (int i = 1; i <= n; ++i) {
			while((! que.empty()) && (que.front().second < i-k)) que.pop_front();
			if (! que.empty()) dp[i][s] = que.front().first + val[i-1];
			else dp[i][s] = -INF;

			ll offer = dp[i][s-1];
			while((! que.empty()) && (que.back().first <= offer)) que.pop_back();
			que.push_back({offer, i});
		}
	}
	
	ll res = -INF;
	for (int i = n; i > n-k; --i) res = max(res, dp[i][x]);
	if (res < 0) cout << -1 << '\n';
	else cout << res << '\n';
}