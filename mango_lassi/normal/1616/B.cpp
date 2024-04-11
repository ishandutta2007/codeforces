#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	string str;
	cin >> str;

	int j = 1;
	for (; j < n; ++j) {
		if (str[j-1] < str[j] || str[0] == str[j]) break;
	}

	for (int i = 0; i < j; ++i) cout << str[i];
	for (int i = j-1; i >= 0; --i) cout << str[i];
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}