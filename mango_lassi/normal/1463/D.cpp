#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<bool> used(2*n, 0);
	for (int i = 0; i < n; ++i) {
		int b;
		cin >> b;
		used[b-1] = 1;
	}

	// Matching with least MIN-pairs?
	// 	Match every 1 to the next 0

	int max_min = 0;
	int cur = 0;
	for (int i = 0; i < 2*n; ++i) {
		if (used[i]) ++cur;
		else if (cur > 0) {
			--cur;
			++max_min;
		}
	}

	int max_max = 0;
	cur = 0;
	for (int i = 2*n-1; i >= 0; --i) {
		if (used[i]) ++cur;
		else if (cur > 0) {
			--cur;
			++max_max;
		}
	}

	int min_x = n - max_max;
	int max_x = max_min;
	cout << max_x - min_x + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}