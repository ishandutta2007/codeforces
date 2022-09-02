#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<int> vals(n);
	for (int i = 0; i < n; ++i) cin >> vals[i];

	vector<int> res;
	vector<pair<int, int>> ans(n);
	int a = vals[0];
	for (int i = 1; i < n; ++i) {
		ans[i] = {a, vals[i]};
		if (vals[i] > a) swap(a, vals[i]);
		res.push_back(vals[i]);
	}

	for (int qi = 0; qi < q; ++qi) {
		ll m;
		cin >> m;
		if (m < n) {
			cout << ans[m].first << ' ' << ans[m].second << '\n';
		} else {
			m = (m - n) % (n-1);
			cout << a << ' ' << res[m] << '\n';
		}
	}
}