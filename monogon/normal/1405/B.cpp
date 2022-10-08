#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long long cur = 0;
		for (int i = 0; i < n; ++i) {
			long long x; cin >> x;
			cur = max(0LL, cur + x);
		}
		cout << cur << "\n";
	}
}