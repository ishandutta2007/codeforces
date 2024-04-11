#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n; long long k; cin >> n >> k;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a.begin() + 1, a.end());
		long long sum = 0;
		for (int i = 1; i <= n; i++) sum += a[i];
		long long ans = sum - k;
		for (int i = n; i >= 2; i--) {
			sum -= a[i];
			long long now = sum + 1ll * a[1] * (n - i + 1);
			if (now <= k) ans = min(ans, (long long)(n - i + 1));
			else ans = min(ans, (now - k + n - i + 1) / (n - i + 2) + n - i + 1);
		}
		cout << max(0ll, ans) << endl;
	}
	return 0;
}