#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		auto query = [&](int x) {
			cout << "? " << x << endl;
			int ans; cin >> ans;
			return ans;
		};
		vector<int> ans(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			if (ans[i]) continue;
			vector<int> cyc;
			cyc.push_back(query(i));
			while (1) {
				int val = query(i);
				if (val == cyc[0]) break;
				cyc.push_back(val);
			}
			for (int i = 0; i < (int)cyc.size(); i++) {
				ans[cyc[i]] = cyc[(i + 1) % cyc.size()];
			}
		}
		cout << "!";
		for (int i = 1; i <= n; i++) cout << " " << ans[i];
		cout << endl;
	}
	return 0;
}