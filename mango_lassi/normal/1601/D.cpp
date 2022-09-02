#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// returns number of elements strictly smaller than v in vec
template<class T>
int bins(const vector<T>& vec, T v) {
	int low = 0;
	int high = vec.size();
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid] < v) low = mid + 1;
		else high = mid;
	}
	return low;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	ll d;
	cin >> n >> d;

	vector<pair<ll, ll>> good, tmp;
	for (int i = 0; i < n; ++i) {
		ll s, a;
		cin >> s >> a;
		if (s < d) continue;
		if (s >= a) good.emplace_back(s, a);
		else tmp.emplace_back(a, s);
	}
	sort(good.begin(), good.end());
	sort(tmp.begin(), tmp.end());
	
	// Loop bad ones in increasing order of neatness
	// Once neatness surpasses the skill of a good guy, mark that from this point on skill must be at least their neatness

	int ind = 0;
	ll min_skill = 0;
	vector<pair<ll, ll>> bad;
	for (int i = 0; i < tmp.size(); ++i) {
		while(ind < good.size() && good[ind].first < tmp[i].first) {
			min_skill = max(min_skill, good[ind].second);
			++ind;
		}
		if (tmp[i].second >= min_skill) {
			bad.emplace_back(tmp[i].second, tmp[i].first);
		}
	}

	int m = bad.size(), res = good.size();
	vector<int> dp(m + 1, (int)good.size());
	sort(bad.begin(), bad.end());
	for (int i = m-1; i >= 0; --i) {
		int nxt = bins(bad, make_pair(bad[i].second, 0ll));
		dp[i] = max(dp[nxt] + 1, dp[i + 1]);
		res = max(res, dp[i]);
	}
	cout << res << '\n';
}