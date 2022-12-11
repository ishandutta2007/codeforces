#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (; t; t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector <int> h(n);
		for (int i = 0; i < n; i++) {
			cin >> h[i];
		}
		bool ok = true;
		for (int i = 0; i < n - 1; i++) {
			int lowest = max(h[i + 1] - k, 0);
			if (h[i] > lowest) {
				m += h[i] - lowest;
				h[i] = lowest;
			}
			if (h[i] < lowest) {
				int need = lowest - h[i];
				if (need > m) {
					cout << "NO\n";
					ok = false;
					break;
				}
				m -= need;
			}
		}
		if (ok) cout << "YES\n";
	}
	return 0;
}