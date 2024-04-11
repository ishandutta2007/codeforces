#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int a, b;
	cin >> a >> b;
	if (a < b) swap(a, b);

	if ((a + b) & 1) {
		int h0 = (a + b) >> 1;
		int h1 = h0 + 1;
		
		int high0 = min(h0, a) + min(h1, b);
		int high1 = min(h1, a) + min(h0, b);
		int low0 = max(0, a - h1) + max(0, b - h0);
		int low1 = max(0, a - h0) + max(0, b - h1);

		vector<int> cans;
		for (int i = low0; i <= high0; i += 2) cans.push_back(i);
		for (int i = low1; i <= high1; i += 2) cans.push_back(i);
		sort(cans.begin(), cans.end());
		cans.erase(unique(cans.begin(), cans.end()), cans.end());

		cout << cans.size() << '\n';
		for (int i : cans) cout << i << ' '; cout << '\n';
	} else {
		int h = (a + b) >> 1;
		int high = min(h, a) + min(h, b);
		int low = max(0, a - h) + max(0, b - h);
		cout << (high - low) / 2 + 1 << '\n';
		for (int i = low; i <= high; i += 2) cout << i << ' '; cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}