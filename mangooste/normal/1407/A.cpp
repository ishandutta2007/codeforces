#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		array<int, 2> cnt{0, 0};
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			cnt[x]++;
		}
		if (cnt[0] * 2 >= n) {
			cout << cnt[0] << '\n';
			for (int i = 0; i < cnt[0]; i++) {
				cout << 0 << ' ';
			}
			cout << '\n';
		} else {
			cnt[1] -= cnt[1] % 2;
			cout << cnt[1] << '\n';
			for (int i = 0; i < cnt[1]; i++) {
				cout << 1 << ' ';
			}
			cout << '\n';
		}
	}
}