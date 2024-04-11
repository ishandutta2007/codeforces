#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	int tot = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		tot += a - 1;
	}
	if (tot & 1) {
		cout << "errorgorn\n";
	} else {
		cout << "maomao90\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}