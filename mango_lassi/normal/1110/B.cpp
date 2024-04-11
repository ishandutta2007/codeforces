#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<ll> xs(n);
	for (int i = 0; i < n; ++i) cin >> xs[i];
	
	vector<ll> diffs;
	for (int i = 1; i < n; ++i) {
		ll dx = xs[i] - xs[i-1] - 1;
		diffs.push_back(dx);
	}
	sort(diffs.begin(), diffs.end());

	ll res = xs[n-1] - xs[0] + 1;
	for (int i = (int)diffs.size() - 1; i > (int)diffs.size() - k; --i) {
		res -= diffs[i];
	}
	cout << res << '\n';
}