#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	ll k;
	cin >> n >> k;

	vector<ll> vals(n);
	for (int i = 0; i < n; ++i) cin >> vals[i];
	sort(vals.begin(), vals.end());
	ll res = vals[n-1] - vals[0];

	int a = 0;
	int b = n-1;
	while(a < b && k > 0) {
		if (a+1 < n-b) {
			ll mult = a+1;
			ll diff = vals[a+1] - vals[a];
			if (k / mult >= diff) {
				res -= diff;
				k -= diff * mult;
				++a;
			} else {
				res -= k / mult;
				k = 0;
			}
		} else {
			ll mult = n-b;
			ll diff = vals[b] - vals[b-1];
			if (k / mult >= diff) {
				res -= diff;
				k -= diff * mult;
				--b;
			} else {
				res -= k / mult;
				k = 0;
			}
		}
	}
	cout << res << '\n';
}