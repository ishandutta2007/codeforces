#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

void solve() {
	int n, r;
	cin >> n >> r;
	vector<ll> locs(n);
	for (int i = 0; i < n; ++i) cin >> locs[i];
	sort(locs.begin(), locs.end());

	int res = 0;
	while(! locs.empty()) {
		if (locs.back() <= res * r) break;
		++res;
		ll v = locs.back();
		while(locs.back() == v) locs.pop_back();
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) solve();
}