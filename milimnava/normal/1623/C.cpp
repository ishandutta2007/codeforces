#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		int l = 0, r = 1e9, ans = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			for (int i = 0; i < n; i++) b[i] = 0;
			int ok = 1;
			for (int i = n - 1; i >= 2; i--) {
				if (a[i] + b[i] < mid) {
					ok = 0;
					break;
				}
				int can = min(a[i] / 3, (a[i] + b[i] - mid) / 3);
				b[i - 2] += can * 2; b[i - 1] += can;
			}
			if (ok && a[0] + b[0] >= mid && a[1] + b[1] >= mid) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		cout << ans << endl;
	}
	return 0;
}