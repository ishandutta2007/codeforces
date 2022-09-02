#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 500;
int res[N][N];

void solve() {
	int n;
	cin >> n;

	/*
	vector<int> perm(n);
	for (int i = 0; i < n; ++i) perm[i] = i+1;
	for (int it = 0; it < 1e; ++it) {
	*/
	
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x <= y; ++x) res[y][x] = -1;
	}

	for (int i = 0; i < n; ++i) {
		int k; // = perm[i];
		cin >> k;

		int y = i, x = i;
		res[y][x] = k;
		for (int j = k-1; j > 0; --j) {
			if (x > 0 && res[y][x-1] == -1) --x;
			else if (y+1 < n && res[y+1][x] == -1) ++y;
			else assert(false);
			res[y][x] = k;
		}
	}

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x <= y; ++x) cout << res[y][x] << ' '; cout << '\n';
	}
	
	// 	next_permutation(perm.begin(), perm.end());
	// }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();

	/*
	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
	*/
}