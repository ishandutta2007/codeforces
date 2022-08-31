#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using ull = uint64_t;

using namespace std;

const int MX = 107;

int a[MX];
int b[MX];

int s[MX], h[MX];
bool was[MX];

bool can(int id, int x) {
	int bal = h[id];
	if (s[id] <= x) {
		for (int i = s[id]; i <= x; i++) {
			bal += a[i];
			if (bal < 0) {
				return false;
			}
		}
		for (int i = s[id]; i <= x; i++) {
			a[i] = 0;
		}
		return true;
	} else {
		for (int i = s[id]; i >= x; i--) {
			bal += a[i];
			if (bal < 0) {
				return false;
			}
		}
		for (int i = s[id]; i >= x; i--) {
			a[i] = 0;
		}
		return true;
	}
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> s[i] >> h[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[j] = b[j];
		}
		vector<int> order;
		for (int j = 1; j <= m; j++) {
			was[j] = false;
		}
		bool ok = true;
		for (int j = 1; j <= m; j++) {
			bool fnd = false;
			for (int k = 1; k <= m; k++) {
				if (!was[k] && can(k, i)) {
					fnd = true;
					was[k] = true;
					order.push_back(k);
					break;
				}
			}
			if (!fnd) {
				ok = false;
				break;
			}
		}

		if (ok) {
			cout << i << "\n";
			for (int x : order) {
				cout << x << " ";
			}
			cout << "\n";
			return 0;
		}
	}

	cout << -1 << "\n";
	return 0;
}