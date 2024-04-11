#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	// 2 elements possible IFF xor all = 0
	// 3 elements possible IFF some suffix = some prefix = xor all

	int tot = 0;
	vector<int> vals(n);
	for (int& v : vals) {
		cin >> v;
		tot ^= v;
	}

	int a = n;
	int b = -1;

	for (int i = 0, cur = 0; i < n; ++i) {
		cur ^= vals[i];
		if (cur == tot) a = min(a, i);
	}
	for (int i = n-1, cur = 0; i >= 0; --i) {
		cur ^= vals[i];
		if (cur == tot) b = max(b, i);
	}

	bool res = (tot == 0) || (a + 1 < b);
	cout << (res ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}