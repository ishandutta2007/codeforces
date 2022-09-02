#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	// n even
	//	-> can't change total xor
	// 	-> can't change total xor of any 2 by 2 subgrid
	// 	-> Every row either equals first row or is first row flipped
	
	vector<string> mat0(n), mat1(n);
	for (int y = 0; y < n; ++y) cin >> mat0[y];
	for (int y = 0; y < n; ++y) cin >> mat1[y];

	for (int y = 0; y < n; ++y) {
		bool match = 1, inv = 1;
		for (int x = 0; x < n; ++x) {
			char c = mat0[y][x] ^ mat1[y][x] ^ '0';
			char c0 = mat0[0][x] ^ mat1[0][x] ^ '0';
			if (c == c0) inv = 0;
			else match = 0;
		}
		if (!match && !inv) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}