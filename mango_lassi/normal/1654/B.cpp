#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	string str;
	cin >> str;

	vector<int> cou(26, 0);
	for (char c : str) ++cou[c - 'a'];

	bool del = 1;
	for (auto c : str) {
		--cou[c - 'a'];
		del &= (cou[c - 'a'] > 0);
		if (! del) cout << c;
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