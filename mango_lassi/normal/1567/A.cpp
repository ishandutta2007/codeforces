#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	string str;
	cin >> str;

	bool pre = 0;
	for (int i = 0; i < n; ++i) {
		if (str[i] == 'U' || str[i] == 'D') {
			cout << (char)(str[i] ^ ('D' ^ 'U'));
			pre = 0;
		} else {
			if (pre) {
				cout << 'R';
			} else {
				cout << 'L';
			}
			pre ^= 1;
		}
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