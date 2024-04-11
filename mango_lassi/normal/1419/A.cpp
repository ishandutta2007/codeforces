#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	
	// 1 wins on odd and can select odd positions
	// 2 wins on even and can select even positions

	int odd = 0, even = 0;
	string str;
	cin >> str;
	for (int i = 0; i < n; ++i) {
		int b1 = (str[i] - '0') & 1;
		int b2 = 1 ^ (i & 1);
		if (b1 == b2) {
			if (b2) ++odd;
			else ++even;
		}
	}

	if (n & 1) {
		cout << (odd ? 1 : 2) << '\n';
	} else {
		cout << (even ? 2 : 1) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}