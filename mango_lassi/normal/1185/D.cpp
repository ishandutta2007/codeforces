#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int solve() {
	int n;
	cin >> n;

	vector<pair<int, int>> vals(n);
	for (int i = 0; i < n; ++i) {
		cin >> vals[i].first;
		vals[i].second = i+1;
	}
	sort(vals.begin(), vals.end());

	vector<int> pref(n, vals[1].first - vals[0].first);
	for (int i = 2; i < n; ++i) {
		int d = vals[i].first - vals[i-1].first;
		if (d != pref[i-1]) pref[i] = -1;
	}

	vector<int> suff(n, vals[n-1].first - vals[n-2].first);
	for (int i = n-3; i >= 0; --i) {
		int d = vals[i+1].first - vals[i].first;
		if (d != suff[i+1]) suff[i] = -1;
	}
	
	for (int j = 0; j < n; ++j) {
		if (j >= 2 && pref[j-1] == -1) continue;
		if (j+2 < n && suff[j+1] == -1) continue;

		if (j > 0 && j+1 < n) {
			int d = vals[j+1].first - vals[j-1].first;
			if (j >= 2 && pref[j-1] != d) continue;
			if (j+2 < n && suff[j+1] != d) continue;
		}
		return vals[j].second;
	}
	return -1;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int ans = solve();
	cout << ans << '\n';
}