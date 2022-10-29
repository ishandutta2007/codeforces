#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int> cnt(101, 0);
		for (int i = 1; i <= n; i++) {
			int x; cin >> x;
			++cnt[abs(x)];
		}
		int ans = (cnt[0] > 0);
		for (int i = 1; i <= 100; i++) {
			ans += min(cnt[i], 2);
		}
		cout << ans << endl;
	}
	return 0;
}