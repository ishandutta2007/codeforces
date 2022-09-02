#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, m;
	cin >> n >> m;

	string str;
	cin >> str;

	vector<int> le(n, m+1), ri(n, m+1);
	for (int i = 0; i < n; ++i) {
		if (str[i] == '1') {
			le[i] = 0;
			ri[i] = 0;
		}
	}
	for (int i = 1; i < n; ++i) le[i] = min(le[i], le[i-1] + 1);
	for (int i = n-2; i >= 0; --i) ri[i] = min(ri[i], ri[i+1] + 1);
	for (int i = 0; i < n; ++i) {
		if (min(le[i], ri[i]) <= m && (le[i] == 0 || le[i] != ri[i])) cout << '1';
		else cout << '0';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}