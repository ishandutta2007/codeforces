#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	vector<int> oks = {6, 10, 14, 15, 35};

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		bool fnd = false;

		for (int i = 0; i < oks.size(); i++) {
			for (int j = i + 1; j < oks.size(); j++) {
				for (int k = j + 1; k < oks.size(); k++) {
					int a = oks[i], b = oks[j], c = oks[k], d = n - a - b - c;

					if (!fnd && d != a && d != b && d != c && d > 0) {
						cout << "YES\n";
						cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
						fnd = true;
					}
				}
			}
		}

		if (!fnd) {
			cout << "NO\n";
		}
	}
}