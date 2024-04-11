#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> as(n), bs(n);
	for (int i = 0; i < n; ++i) cin >> as[i] >> bs[i];

	// Binary search answer
	int low = 0;
	int high = n;
	while(low != high) {
		int tar = (low + high + 1) >> 1;
		int cur = 0;
		for (int i = 0; i < n; ++i) {
			if (bs[i] >= cur && as[i] >= tar - (cur + 1)) ++cur;
		}
		if (cur >= tar) low = tar;
		else high = tar - 1;
	}
	cout << low << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}