#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;

const ll INF = 1e16;
const int N = 1e5;
ll dp[N + 1];

vector<pair<int, int>> lefts;
vector<pair<int, int>> rights;

ll offer(int i, int h, bool sid) {
	ll res = 0;
	for (int j = 0; j < h; ++j) {
		if (sid) {
			if (lefts[i + j].second == rights[i + (j + 1) % h].second) return INF;
			res += max(lefts[i + j].first, rights[i + (j + 1) % h].first);
		} else {
			if (rights[i + j].second == lefts[i + (j + 1) % h].second) return INF;
			res += max(rights[i + j].first, lefts[i + (j + 1) % h].first);
		}
	}
	return res;
}


int main() {
	// One with maximum L connects to the one with maximum R
	// Then we get a new guest.
	// clearly optimal if it isn't the same guest with both L and R
	// How to make sure that the result is
	ios_base::sync_with_stdio(false);	
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		lefts.push_back({l, i});
		rights.push_back({r, i});
	}

	sort(lefts.begin(), lefts.end());
	sort(rights.begin(), rights.end());
	
	ll res = n;
	for (int i = 0; i < n; ++i) res += max(lefts[i].first, rights[i].first);
	cout << res << '\n';

	/*
	dp[n] = n;
	
	for (int i = n-1; i >= 0; --i) {
		if (lefts[i].second == rights[i].second) {
			dp[i] = dp[i+1] + max(lefts[i], rights[i]);
		}
		if (i+1 < n) {
			dp[i] = min(dp[i], dp[i+2] + offer(i, 2, true));
		}
		if (i+2 < n) {
			dp[i] = min(dp[i], dp[i+3] + offer(i, 3, true));
			dp[i] = min(dp[i], dp[i+3] + offer(i, 3, false));
		}
	}
	cout << dp[0] << '\n';
	*/
}