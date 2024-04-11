#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while (T--) {
		int n; cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		int ans = 1e9;
		for (int i = 0; i <= 2; i++) {
			for (int j = 0; j <= 2; j++) {
				int maxn = 0, ok = 1;
				for (int k = 0; k < n; k++) {
					maxn = max(maxn, (a[k] - i - j * 2 + 2) / 3);
					if (i + j <= 1) {
						if (a[k] % 3 == 1 && !i) ok = 0;
						if (a[k] % 3 == 2 && !j) ok = 0;
					}
					if (a[k] == 1 && !i) ok = 0;
					if (a[k] % 3 == 0) maxn = max(maxn, (a[k] / 3 - (i && j)));
				}
				if (ok) ans = min(ans, maxn + i + j);
			}
		}
		cout << ans << endl;
	}
	return 0;
}