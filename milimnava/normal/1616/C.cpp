#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		int ans = max(0, n - 2);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int cnt = 0;
				double d = (double)(a[j] - a[i]) / (j - i);
				double now = a[i] - i * d;
				for (int k = 0; k < n; k++) {
					++cnt;
					if (fabs(now - a[k]) < 1e-6) --cnt;
					now += d;
				}
				ans = min(ans, cnt);
			}
		}
		cout << ans << endl;
	}
	return 0;
}