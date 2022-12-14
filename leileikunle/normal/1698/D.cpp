#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
using pii = pair<int, int>;

void solve() {

	int n;
	cin >> n;
	int l = 1, r = n;
	while (l < r) {
		int mid = l + r >> 1;
		cout << "? " << l << " " << mid << endl;
		int cnt(0);
		for (int i = l, x; i <= mid; i++) {
			cin >> x;
			if (x >= l and x <= mid) cnt++;
		}
		if (cnt & 1) r = mid;
		else l = mid + 1;
	}
	cout << "! " << l << endl;


}
signed main() {
//	cin.tie(0) -> ios::sync_with_stdio(false);
	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}