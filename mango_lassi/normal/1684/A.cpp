#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	string str;
	cin >> str;

	if (str.size() == 2) {
		cout << str[1] << '\n';
	} else {
		sort(str.begin(), str.end());
		cout << str[0] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}