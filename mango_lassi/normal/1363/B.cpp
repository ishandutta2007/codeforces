#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	string str;
	cin >> str;
	int n = str.size();

	int cur = 0, tot = 0;
	for (int i = 0; i < n; ++i) {
		if (str[i] == '1') ++tot;
	}
	
	int res = n;
	for (int i = 0; i <= n; ++i) {
		int off = min(cur + ((n-i) - (tot - cur)), (i - cur) + (tot - cur));
		res = min(res, off);

		if (i == n) break;
		if (str[i] == '1') ++cur;
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		solve();
	}
}