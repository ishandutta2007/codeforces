#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	string str;
	cin >> str;

	int cou = 0;
	for (auto c : str) {
		if (c == '0') ++cou;
	}
	if ((cou & 1) || str[0] != '1' || str[n-1] != '1') {
		cout << "NO\n";
	} else {
		cout << "YES\n";

		int cur = 0;
		string sa(n, '_'), sb(n, '_');
		for (int i = 0; i < n; ++i) {
			if (str[i] == '1') {
				++cur;
				if (2*cur <= n - cou) {
					sa[i] = '(';
					sb[i] = '(';
				} else {
					sa[i] = ')';
					sb[i] = ')';
				}
			} else {
				int cur2 = i+1 - cur;
				if (cur2 & 1) {
					sa[i] = '(';
					sb[i] = ')';
				} else {
					sa[i] = ')';
					sb[i] = '(';
				}
			}
		}
		cout << sa << '\n' << sb << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}