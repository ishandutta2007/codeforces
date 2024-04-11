#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	string str, tar;
	cin >> str >> tar;

	array<int, 4> cou;
	for (int j = 0; j < 4; ++j) cou[j] = 0;

	for (int i = 0; i < n; ++i) {
		cou[(str[i] - '0') + 2 * (tar[i] - '0')] += 1;
	}
	
	// After two operations:
	// 	a ones, b zeroes
	// 	-> b + 1 ones, a - 1 zeroes
	// 	-> a ones, b zeroes
	
	int ones0 = cou[1] + cou[3];
	int ones1 = cou[2] + cou[3];
	int zeros0 = n - ones0;
	int zeros1 = n - ones1;

	int res = n + 1;
	if (ones0 == ones1) res = min(res, cou[1] + cou[2]);
	if (zeros0 + 1 == ones1) res = min(res, cou[0] + cou[3]);
	if (res > n) cout << -1 << '\n';
	else cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}