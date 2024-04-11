#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		int minL, maxR, valL = 0, valR = 0, maxn = 0, minval = 0;
		for (int i = 1; i <= n; i++) {
			int l, r, c; cin >> l >> r >> c;
			if (i == 1) {
				minL = l; maxR = r;
				valL = valR = c;
				maxn = r - l + 1;
				minval = c;
			} else {
				if (l < minL) minL = l, valL = c;
				else if (l == minL) valL = min(valL, c);
				if (r > maxR) maxR = r, valR = c;
				else if (r == maxR) valR = min(valR, c);
				if (r - l + 1 > maxn) {
					maxn = r - l + 1;
					minval = c;
				} else if (r - l + 1 == maxn) minval = min(minval, c);
			}
			int ans = valL + valR;
			if (maxR - minL + 1 == maxn) ans = min(ans, minval);
			cout << ans << endl;
		}
	}
	return 0;
}