#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll INF = 1e9;
const ll N = 3 * (ll)1e5;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	ll min_x = INF;
	ll max_x = -INF;
	ll min_y = INF;
	ll max_y = -INF;

	ll max_xy = -INF; // max x + y
	ll max_xny = -INF; // max x - y
	ll max_nxy = -INF; // max y - x
	ll max_nxny = -INF; // max -(x + y)

	for (int i = 0; i < n; ++i) {
		ll x, y;
		cin >> x >> y;
		
		min_x = min(x, min_x);
		max_x = max(x, max_x),
		min_y = min(y, min_y);
		max_y = max(y, max_y);

		max_xy = max(x+y, max_xy);
		max_xny = max(x-y, max_xny);
		max_nxy = max(y-x, max_nxy);
		max_nxny = max(-(x+y), max_nxny);
	}

	// For each k, find the subsequence that maximizes
	// (|xs[a1] - xs[a2]| + |ys[a1] - ys[a2]|) + ... + (|xs[ak] - xs[a1]| + |ys[ak - ys[a1]|)
	// First x's are increasing, then decreasing, then increasing again
	// First y's are increasing, then decreasing, then increasing again
	// Answer is just 2x width + 2x height
	// When n >= 4, answer is trivial, and always the same.
	// When n = 3, one poll has to be both an extreme in x and y -coordinates.
	
	ll ans = -INF;
	ans = max(ans, max_xy - min_x - min_y);
	ans = max(ans, max_xny - min_x + max_y);
	ans = max(ans, max_nxy + max_x - min_y);
	ans = max(ans, max_nxny + max_x + max_y);
	cout << 2 * ans;

	ll sum = max_x - min_x + max_y - min_y;
	for (int i = 4; i <= n; ++i) cout << ' ' << 2 * sum; cout << '\n';
}