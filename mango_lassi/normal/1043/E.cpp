#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	// Just sort them by difference
	vector<pair<ll, int>> diff(n);
	vector<pair<ll, ll>> els(n);
	vector<ll> ans(n, 0);
	for (int i = 0; i < n; ++i) {
		ll a, b;
		cin >> a >> b;
		els[i] = {a, b};
		diff[i] = {a-b, i};
	}

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;

		ll val = 0;
		if (diff[a].first < diff[b].first) {
			val = els[a].first + els[b].second;
		} else {
			val = els[b].first + els[a].second;
		}
		ans[a] -= val;
		ans[b] -= val;
	}
	
	// Sort must be here
	sort(diff.begin(), diff.end());

	vector<ll> pref_sum(n, 0);
	vector<ll> suff_sum(n, 0);
	for (int j = 0; j < n; ++j) {
		int i = diff[j].second;
		pref_sum[j] += els[i].first;
		if (j > 0) pref_sum[j] += pref_sum[j-1];
	}
	for (int j = n-1; j >= 0; --j) {
		int i = diff[j].second;
		suff_sum[j] += els[i].second;
		if (j < n-1) suff_sum[j] += suff_sum[j+1];
	}
	
	for (int j = 0; j < n; ++j) {
		int i = diff[j].second;
		ans[i] += (n-1-j) * els[i].first;
		ans[i] += j * els[i].second;
		if (j > 0) ans[i] += pref_sum[j-1];
		if (j < n-1) ans[i] += suff_sum[j+1];
	}
	
	for (int i = 0; i < n; ++i) cout << ans[i] << ' '; cout << '\n';
}