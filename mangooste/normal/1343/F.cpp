#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<set<int>> segs(n - 1);
		for (auto &el : segs) {
			int k;
			cin >> k;
			for (int i = 0; i < k; i++) {
				int x;
				cin >> x;
				el.insert(x);
			}
		}

		vector<set<int>> segs_save = segs;

		vector<int> ans;
		for (int fir = 1; fir <= n; fir++) {
			vector<int> loc(n);
			loc[0] = fir;

			bool ok = true;
			for (auto &el : segs) {
				el.erase(fir);
			}

			for (int i = 1; i < n && ok; i++) {
				int now = -1;
				for (auto &el : segs) {
					if (el.size() == 1) {
						ok &= (now == -1);
						now = *el.begin();
					}
				}

				for (auto &el : segs) {
					el.erase(now);
				}

				if (now == -1) {
					ok = false;
				}

				loc[i] = now;
			}

			segs = segs_save;

			if (!ok) {
				continue;
			}

			vector<int> where(n);
			for (int i = 0; i < n; i++) {
				where[loc[i] - 1] = i;
			}

			for (auto &els : segs) {
				vector<int> now;
				for (auto el : els) {
					now.push_back(where[el - 1]);
				}
				sort(now.begin(), now.end());
				for (int i = 1; i < now.size(); i++) {
					ok &= now[i] == now[i - 1] + 1;
				}
			}

			if (ok) {
				ans = loc;
				break;
			}
		}

		for (auto el : ans) {
			cout << el << ' ';
		}
		cout << '\n';
	}
}