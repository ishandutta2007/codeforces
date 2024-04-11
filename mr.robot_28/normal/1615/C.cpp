#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define x first
#define y second
#define sz(a) (int)a.size()
const int N = 2e5 + 100;
const int mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == '0' && b[i] == '0') {
				cnt1++;
			}
			else if (a[i] == '0' && b[i] == '1') {
				cnt2++;
			}
			else if (a[i] == '1' && b[i] == '0') {
				cnt3++;
			}
			else {
				cnt4++;
			}
		}
		int ans = 1e9;
		if (cnt2 == 0 && cnt3 == 0) {
			ans = 0;
		}
		if (cnt3 != 0 && cnt3 >= cnt2 && abs(cnt2 - cnt3) <= 1 && (cnt2 + cnt3) % 2 == 0) {
			ans = min(ans, cnt2 + cnt3);
		}
		if (cnt4 != 0 && cnt4 >= cnt1 && abs(cnt4 - cnt1) <= 1 && (cnt1 + cnt4) % 2 == 1) {
			ans = min(ans, cnt1 + cnt4);
		}
		if (ans == 1e9) {
			ans = -1;
		}
		cout << ans << "\n";
	}
	return 0;
}