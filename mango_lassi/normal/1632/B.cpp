#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	
	int h = 1;
	while(2*h <= n-1) h *= 2;
	for (int i = 0; i < h; ++i) {
		cout << h-1-i << ' ';
	}
	for (int i = h; i < n; ++i) cout << i << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}