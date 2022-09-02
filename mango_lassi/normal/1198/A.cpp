#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll log2(ll v) {
	int res = 0;
	--v;
	while(v) {
		++res;
		v >>= 1;
	}
	return res;
}

ll bins(ll n, ll t) {
	ll low = 1;
	ll high = n;
	while(low != high) {
		ll mid = (low + high + 1) >> 1;
		ll k = log2(mid);
		if (k*n <= 8*t) low = mid;
		else high = mid - 1;
	}
	return low;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	ll t;
	cin >> n >> t;
	int k = bins(n, t);
	
	vector<int> vals(n);
	for (int i = 0; i < n; ++i) cin >> vals[i];
	sort(vals.begin(), vals.end());

	vector<int> start;
	vector<int> ends;
	for (int i = 0; i < n; ++i) {
		if (i+1 == n || vals[i+1] != vals[i]) start.push_back(i+1);
	}
	for (int i = n-1; i >= 0; --i) {
		if (i == 0 || vals[i-1] != vals[i]) ends.push_back(n-i);
	}

	int r = (int)start.size() - k; // Remove at least this many
	
	int res = n;
	if (r <= 0) {
		res = 0;
	} else {
		for (int j = 0; j <= r; ++j) {
			int a = (j > 0 ? start[j-1] : 0);
			int b = (r-j > 0 ? ends[r-j-1] : 0);
			res = min(res, a + b);
		}
	}
	cout << res << '\n';
}