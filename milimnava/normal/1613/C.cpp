#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n; long long h; cin >> n >> h;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		long long l = 1, r = h, res = h;
		while (l <= r) {
			long long mid = (l + r) / 2;
			long long sum = mid;
			for (int i = 1; i < n; i++) {
				sum = min(h, sum + min(mid, (long long)(a[i] - a[i - 1])));
			}
			if (sum >= h) {
				res = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		cout << res << endl;
	}
	return 0;
}