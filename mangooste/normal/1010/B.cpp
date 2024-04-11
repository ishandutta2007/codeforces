#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int m, n;
	cin >> m >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cout << m << endl;
		int res;
		cin >> res;
		if (!res) return 0;
		p[i] = (res == 1);
	}
	for (int i = 0, L = 1, R = m + 1;; i = (i + 1) % n) {
		int mid = (L + R) / 2;
		cout << mid << endl;
		int res;
		cin >> res;
		if (!res) return 0;
		if (!p[i]) res *= -1;
		(res == 1 ? R : L) = mid;
	}
}