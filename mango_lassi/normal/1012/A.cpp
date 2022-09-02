#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<ll> vals(2*n);
	for (int i = 0; i < 2 * n; ++i) {
		cin >> vals[i];
	}
	sort(vals.begin(), vals.end());

	ll res = (vals[n-1] - vals[0]) * (vals[2*n-1] - vals[n]);
	for (int i = 1; i < n; ++i) {
		ll off = (vals[i+n-1] - vals[i]) * (vals[2*n-1] - vals[0]);
		res = min(res, off);
	}
	cout << res << '\n';
}