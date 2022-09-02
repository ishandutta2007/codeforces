#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;

	vector<int> col(n, 0);
	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;
		if (i < a) ++col[c-1];
		else --col[c-1];
	}

	// 1 op: add +2 or -2
	// 1 op: add +1 to one pile, -1 to another
	int odd_neg = 0, odd_pos = 0, ev_neg = 0, ev_pos = 0;
	for (int& v : col) {
		int x = abs(v);
		if (v < 0) {
			ev_neg += x/2;
			if (x & 1) ++odd_neg;
		} else {
			ev_pos += x/2;
			if (x & 1) ++odd_pos;
		}
	}
	if (odd_neg > odd_pos + 2*ev_pos) {
		cout << odd_neg + ev_neg << '\n';
	} else if (odd_pos > odd_neg + 2*ev_neg) {
		cout << odd_pos + ev_pos << '\n';
	} else {
		cout << (odd_neg + odd_pos) / 2 + ev_neg + ev_pos << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}