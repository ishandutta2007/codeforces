#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

vector<int> xs;

// Count number of elements of xs which are <= x
int find(int x) {
	int low = -1;
	int high = (int)xs.size() - 1;
	while(low != high) {
		int mid = (low + high + 1) >> 1;
		if (xs[mid] > x) {
			high = mid - 1;
		} else {
			low = mid;
		}
	}
	return low + 1;
}

ll solve(int ia, int ib, ll a, ll b) {
	ll cou = find(ib) - find(ia-1);
	if (cou == 0) {
		return a;
	} else if (ia == ib) {
		return b * cou;
	} else {
		int mid = (ia + ib) >> 1;
		ll off1 = solve(ia, mid, a, b) + solve(mid+1, ib, a, b);
		ll off2 = b * cou * (ib - ia + 1);
		return min(off1, off2);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k, a, b;
	cin >> n >> k >> a >> b;
	ll len = 1<<n;

	xs.resize(k);
	for (int i = 0; i < k; ++i) cin >> xs[i];
	sort(xs.begin(), xs.end());

	ll res = solve(1, len, a, b);
	cout << res << '\n';
}