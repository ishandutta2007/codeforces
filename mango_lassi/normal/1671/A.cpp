#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	string str;
	cin >> str;
	
	bool can = 1;
	int cur = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (i == 0 || str[i] == str[i-1]) ++cur;
		else {
			can &= cur > 1;
			cur = 1;
		}
	}
	can &= cur > 1;
	cout << (can ? "YES" : "NO") << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}