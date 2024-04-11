#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> as(n);
	for (int& v : as) cin >> v;
	sort(as.begin(), as.end());

	int res = 1;
	int cou = n;
	for (int i = n; i >= 0; --i) {
		while(cou > 0 && as[cou-1] > i) --cou;
		if (cou >= i) res = max(res, cou + 1);
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}