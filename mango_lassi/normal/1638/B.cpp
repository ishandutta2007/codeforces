#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> even, odd;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (a & 1) odd.push_back(a);
		else even.push_back(a);
	}

	vector<int> ord_even = even, ord_odd = odd;
	sort(ord_even.begin(), ord_even.end());
	sort(ord_odd.begin(), ord_odd.end());

	if (even == ord_even && odd == ord_odd) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}