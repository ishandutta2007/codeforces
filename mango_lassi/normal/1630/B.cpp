#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, k;
	cin >> n >> k;

	// Take shortest range that contains at least this many
	int min_cou = (k-1) + ((n-(k-1)) + 2) / 2;

	vector<int> ord(n), cou(n+1, 0);
	for (int i = 0; i < n; ++i) {
		cin >> ord[i];
		++cou[ord[i]];
	}
	for (int i = 1; i <= n; ++i) cou[i] += cou[i-1];

	pair<int, int> res = {n+1, -1};
	for (int x = 1, y = 1; x <= n; ++x) {
		while(y <= n && cou[y] - cou[x-1] < min_cou) ++y;
		if (y > n) break;
		res = min(res, {y-x, x});
	}

	int x = res.second;
	int y = res.first + res.second;

	cout << x << ' ' << y << '\n';
	int i = 0;
	for (int cou = 0; cou < k-1; ++cou) {
		int cur = 0;
		int j = i;
		for (; 2*cur <= j-i; ++j) {
			if (x <= ord[j] && ord[j] <= y) ++cur;
			
		}
		cout << i+1 << ' ' << j << '\n';
		i = j;
	}
	cout << i+1 << ' ' << n << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}