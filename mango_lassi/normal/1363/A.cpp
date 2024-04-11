#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

bool solve() {
	int n, x;
	cin >> n >> x;
	
	int odd = 0;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		if (v & 1) ++odd;
	}
	if (odd == n) return x & 1;
	if (x == n) return odd & 1;
	return odd > 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		bool res = solve();
		if (res) cout << "YES\n";
		else cout << "NO\n";
	}
}