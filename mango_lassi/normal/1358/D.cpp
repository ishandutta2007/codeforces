#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll ariSum(ll a, ll b) {
	return (a + b) * (b-a+1) >> 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	ll x;
	cin >> n >> x;
	
	vector<ll> ds(n);
	for (ll& v : ds) cin >> v;
	for (int i = 0; i < 2*n; ++i) ds.push_back(ds[i]);

	// Loop over possible start- and endmonths of the vacation
	int a = 0, b = 0;
	ll sum = 0, cur = 0, res = 0;
	while(a < n) {
		ll rem = x - sum;
		ll off = cur;
		if (a == b) {
			off += ariSum(max(1ll, ds[a] - (rem - 1)), ds[a]);
		} else {
			// Take as much left end as possible
			ll off1 = 0;
			if (ds[a] > rem) {
				off1 += ariSum(ds[a] - (rem - 1), ds[a]);
			} else {
				off1 += ariSum(1, ds[a]);
				off1 += ariSum(1, min(ds[b], rem - ds[a]));
			}

			// Take as much right side as possible
			ll off2 = 0;
			if (ds[b] > rem) {
				off2 += ariSum(1, rem);
			} else {
				off2 += ariSum(1, ds[b]);
				off2 += ariSum(max(1ll, ds[a] - (rem - ds[b] - 1)), ds[a]);
			}
			off += max(off1, off2);
		}
		res = max(res, off);

		// Move start or end
		if (a != b && sum + ds[b] > x) {
			++a;
			if (a != b) {
				sum -= ds[a];
				cur -= ariSum(1, ds[a]);
			}
		} else {
			if (a != b) {
				sum += ds[b];
				cur += ariSum(1, ds[b]);
			}
			++b;
		}
	}
	cout << res << '\n';
}