#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<pair<int, int>> as(n);
	for (int i = 0; i < n; ++i) {
		cin >> as[i].first;
		as[i].second = i;
	}
	sort(as.begin(), as.end());

	bool fail = 0;
	for (int i = 0; i < n;) {
		int odd = 0, even = 0;
		int j = i;
		while(j < n && as[j].first == as[i].first) {
			if (as[j].second & 1) ++odd;
			else ++even;
			++j;
		}
		int len = j - i;
		odd -= (len / 2 + (len & i & 1));
		even -= (len / 2 + (len & (i ^ 1) & 1));
		if (odd || even) fail = 1;

		i = j;
	}
	if (fail) cout << "NO\n";
	else cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}