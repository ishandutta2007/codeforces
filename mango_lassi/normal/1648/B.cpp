#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, c;
	cin >> n >> c;

	vector<int> cou(c + 1, 0);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++cou[a];
	}
	for (int x = 1; x <= c; ++x) cou[x] += cou[x-1];

	bool works = 1;
	for (int x = 1; x <= c; ++x) {
		if (cou[x] - cou[x-1] == 0) continue;
		for (int y = 1; x * y <= c; ++y) {
			int a = x * y;
			int b = min(c, x * (y + 1) - 1);
			int cnt = cou[b] - cou[a-1];
			works &= (cnt == 0 || (cou[y] - cou[y-1]) > 0);
		}
	}
	if (works) cout << "Yes\n";
	else cout << "No\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}