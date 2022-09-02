#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void setChar(string& str, int i, char c) {
	if (i >= 0 && i < str.size()) str[i] = c;
}

void solve() {
	string str;
	cin >> str;

	int x, n;
	cin >> x;
	n = str.size();

	string tar(n, '?');

	// str[0] == 1 IFF tar[x] == 1
	for (int i = 0; i < n; ++i) {
		if (str[i] == '0') {
			setChar(tar, i-x, '0');
			setChar(tar, i+x, '0');
		}
	}
	for (int i = 0; i < n; ++i) {
		if (tar[i] == '?') tar[i] = '1';
	}

	bool fail = 0;
	for (int i = 0; i < n; ++i) {
		if (str[i] == '1') {
			if ((i-x < 0 || tar[i-x] == '0') && (i+x >= n || tar[i+x] == '0')) fail = 1;
		}
	}

	if (fail) cout << "-1\n";
	else cout << tar << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}