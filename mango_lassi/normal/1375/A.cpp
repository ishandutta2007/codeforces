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
		int n;
		cin >> n;

		vector<int> vals(n);
		for (int& v : vals) cin >> v;

		int cur = (vals[0] >= 0);
		for (int i = 1; i < n; ++i) {
			cur ^= 1;
			if ((vals[i] >= 0) != cur) vals[i] *= -1;
		}
		for (auto v : vals) cout << v << ' '; cout << '\n';
	}
}