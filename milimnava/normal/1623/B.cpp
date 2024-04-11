#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int> l(n), r(n);
		vector<pair<int, int> > a(n);
		for (int i = 0; i < n; i++) cin >> l[i] >> r[i], a[i] = make_pair(l[i], r[i]);
		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++) {
			int pos = lower_bound(a.begin(), a.end(), make_pair(l[i], r[i])) - a.begin();
			if (pos == 0 || a[pos - 1].first != l[i]) {
				cout << l[i] << " " << r[i] << " " << l[i] << endl;
			} else {
				cout << l[i] << " " << r[i] << " " << a[pos - 1].second + 1 << endl;
			}
		}
	}
	return 0;
}