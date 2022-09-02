#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<ll> as(n);
	for (int i = 0; i < n; ++i) cin >> as[i];

	vector<ll> suff_sum(n, 0);
	for (int i = n-2; i >= 0; --i) suff_sum[i] = as[i+1] + suff_sum[i+1];
	suff_sum.pop_back();

	ll res = as[0] + (n > 1 ? suff_sum[0] : 0);
	sort(suff_sum.begin(), suff_sum.end());
	for (int j = 0; j < k-1; ++j) {
		res += suff_sum.back();
		suff_sum.pop_back();
	}
	cout << res << '\n';
}