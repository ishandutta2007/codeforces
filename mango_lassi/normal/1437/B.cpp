#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	string str;
	cin >> str;

	// Every operation cuts at most 2 pairs 00 or 11
	// Cut two such pairs with every operation
	// As long as there is a 00-pair, there must be a 11-pair as well, unless all of the string
	// but the 00-pair is alternating: 10100101. In this case, we must do one more operation

	int res = 0;
	int ap = 0, bp = 0;
	for (int i = 0; i+1 < n; ++i) {
		if (str[i] == str[i+1]) {
			if (str[i] == '0') ++ap;
			else ++bp;
		}
	}
	cout << max(ap, bp) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int ti = 0; ti < n; ++ti) solve();
}