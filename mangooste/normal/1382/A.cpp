#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		map<int, array<int, 2>> mapa;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			mapa[x][0] = 1;
		}
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			mapa[x][1] = 1;
		}
		bool any = false;
		for (auto [el, ar] : mapa) {
			if (ar[0] + ar[1] == 2) {
				any = true;
				cout << "YES\n1 " << el << '\n';
				break;
			}
		}
		if (!any) {
			cout << "NO\n";
		}
	}
}