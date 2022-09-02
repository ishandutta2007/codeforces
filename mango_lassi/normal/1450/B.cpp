#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, k;
	cin >> n >> k;

	// If possible, the answer must be 1
	vector<pair<int, int>> pos(n);
	for (auto& pr : pos) cin >> pr.first >> pr.second;

	bool can = 0;
	for (int i = 0; i < n; ++i) {
		bool works = 1;
		for (int j = 0; j < n; ++j) {
			if (abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second) > k) works = 0;
		}
		can |= works;
	}
	cout << (can ? 1 : -1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int ti = 0; ti < n; ++ti) solve();
}