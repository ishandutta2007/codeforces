#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	string str;
	cin >> str;
	int n = str.size();
	int res = (int)str.size();
	for (int j = 0; j <= 1; ++j) {
		int even = 0, odd = 0;
		for (int i = 0; i < n; ++i) {
			if (str[i] == '1' || (str[i] == '?' && ((i & 1) == j))) {
				if (i & 1) ++odd;
				else ++even;
			}
			if (even - odd > (n-i)/2 || odd - even > (n-i-1)/2) {
				res = min(res, i + 1);
				break;
			}
		}
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}