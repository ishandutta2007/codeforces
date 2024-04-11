#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, k;
	cin >> n >> k;

	if (k == 0) {
		for (int i = 0; i < ((n-1) ^ i); ++i) {
			int j = i ^ (n-1);
			cout << i << ' ' << j << '\n';
		}
	} else if (k < n-1) {
		cout << n-1 << ' ' << k << '\n';
		cout << 0 << ' ' << ((n-1) ^ k) << '\n';
		vector<int> ban = {0, min(k, (n-1)^k)};

		for (int i = 0; i < ((n-1) ^ i); ++i) {
			bool ext = 0;
			for (int v : ban) ext |= i == v;
			if (ext) continue;

			int j = i ^ (n-1);
			cout << i << ' ' << j << '\n';
		}
	} else {
		if (n <= 4) cout << -1 << '\n';
		else {
			// 111 with 110
			// 001 with 011
			// 000 with 100

			int h = (n+1) / 2;
			cout << n-1 << ' ' << n-2 << '\n';
			cout << 1 << ' ' << h - 1 << '\n';
			cout << 0 << ' ' << h << '\n';
			vector<int> ban = {0, 1, h-1};
			for (int i = 0; i < ((n-1) ^ i); ++i) {
				bool ext = 0;
				for (int v : ban) ext |= i == v;
				if (ext) continue;

				int j = i ^ (n-1);
				cout << i << ' ' << j << '\n';
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}