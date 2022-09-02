#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> vec(n);
	for (int i = 0; i < n; ++i) {
		cin >> vec[i].first;
		vec[i].second = i + 1;
	}
	sort(vec.begin(), vec.end());

	int ans = -1;
	for (int i = 0; i < n; ++i) {
		if (i > 0 && vec[i-1].first == vec[i].first) continue;
		if (i + 1 < n && vec[i+1].first == vec[i].first) continue;
		ans = vec[i].second;
		break;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}