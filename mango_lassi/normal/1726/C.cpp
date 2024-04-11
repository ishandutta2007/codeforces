#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	string str;
	cin >> str;

	// Number of connected components = 1 + number of occurrences of ))
	int res = 1;
	for (int i = 0; i + 1 < 2*n; ++i) {
		if (str[i] == ')' && str[i+1] == ')') ++res;
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}