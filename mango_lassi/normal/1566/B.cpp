#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	string str;
	cin >> str;

	// Only ones -> 0
	// Zeroes and ones, only one segment of zeroes -> 1
	// Otherwise -> 2

	int oc = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '0' && (i == 0 || str[i-1] == '1')) ++oc;
	}
	cout << min(oc, 2) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}