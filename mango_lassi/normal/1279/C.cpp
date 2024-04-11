#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int n, m;
		cin >> n >> m;

		vector<int> as(n);
		for (int& v : as) {
			cin >> v;
			--v;
		}

		vector<int> ind(n, -1);
		for (int j = 0; j < m; ++j) {
			int x;
			cin >> x;
			ind[x-1] = j;
		}

		int mn = m;
		ll res = m;
		for (int i = n-1; i >= 0; --i) {
			int v = ind[as[i]];
			if (v != -1 && mn > v) {
				mn = v;
				res += 2 * (i - v);
			}
		}
		cout << res << '\n';
	}
}