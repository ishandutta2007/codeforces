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
		ll s;
		cin >> n >> s;
		vector<ll> as(n);
		for (int i = 0; i < n; ++i) cin >> as[i];

		ll sum = 0;
		ll sum_skip = 0;
		int skip_ind = 0;

		pair<int, int> res = {0, 0};
		for (int i = 0; i < n; ++i) {
			if (sum_skip + as[i] > sum) {
				sum_skip = sum;
				skip_ind = i+1;
			} else sum_skip += as[i];

			sum += as[i];
			if (sum <= s) res = max(res, {i+1, 0});
			if (sum_skip <= s) res = max(res, {i, skip_ind});
		}
		cout << res.second << '\n';
	}
}