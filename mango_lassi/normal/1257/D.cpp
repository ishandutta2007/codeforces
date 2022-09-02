#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int bins(const vector<pair<ll, ll>>& vec, ll v, int rev) {
	int low = -rev;
	int high = (int)vec.size() - rev;
	while(low != high) {
		int mid = (low + high + rev) >> 1;
		if (vec[mid].first >= v) {
			if (rev) low = mid;
			else high = mid;
		} else {
			if (rev) high = mid - 1;
			else low = mid + 1;
		}
	}
	return low;
}

void solve() {
	int n;
	cin >> n;
	vector<ll> as(n);
	for (int i = 0; i < n; ++i) cin >> as[i];

	int m;
	cin >> m;
	vector<pair<ll, ll>> bs(m);
	for (int i = 0; i < m; ++i) {
		cin >> bs[i].first >> bs[i].second;
		swap(bs[i].first, bs[i].second);
	}
	sort(bs.begin(), bs.end());
	
	vector<pair<ll, ll>> act;
	for (int i = 0; i < m; ++i) {
		while (! act.empty() && act.back().second <= bs[i].second) act.pop_back();
		if (act.empty() || act.back().first < bs[i].first) act.push_back(bs[i]);
	}

	vector<pair<ll, ll>> maxes;
	vector<int> dp(n+1, n+1);
	dp[n] = 0;
	for (int i = n-1; i >= 0; --i) {
		while(! maxes.empty() && maxes.back().first <= as[i]) maxes.pop_back();
		maxes.emplace_back(as[i], i);

		int low = 0;
		int high = n-i;
		while(low != high) {
			// Can we kill "mid" monsters?
			int mid = (low + high + 1) >> 1;
			
			// Find hero with most strength and at least "mid" stamina
			int x = bins(act, mid, 0);
			
			if (x < act.size()) {
				// Find monster with at least act[x].second + 1 strength
				int y = bins(maxes, act[x].second + 1, 1);
				if (y < 0 || maxes[y].second >= i + mid) {
					low = mid;
				} else {
					high = mid - 1;
				}
			} else {
				high = mid - 1;
			}
		}
		dp[i] = dp[i + low] + 1;
	}

	if (dp[0] > n) cout << -1 << '\n';
	else cout << dp[0] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}