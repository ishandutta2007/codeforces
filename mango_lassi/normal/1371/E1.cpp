#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, p;
	cin >> n >> p;

	vector<int> as(n);
	for (int& v : as) cin >> v;
	sort(as.begin(), as.end());
	
	// First select last, then second-to-last, and so on
	// Ways to select i: max(0, (i+1) - max(0, as[i] - x))
	// Each one bans some prefix, some suffix, and some positions with distance p from each other

	int low = 1;
	for (int i = 0; i < n; ++i) {
		low = max(low, as[i] - i);
	}
	int high = INF;
	for (int i = p-1; i < n; i += p) {
		high = min(high, as[i]);
	}
	int m = high - low + 1;

	if (m <= 0) {
		cout << 0 << '\n';
		return 0;
	}

	vector<int> can(m, 0); // can[j]: can we do x = low + j?
	for (int i = 0; i < n; ++i) {
		// When x = as[i] - ((i+1) % p) - kp, we get
		// ((i+1) - (i+1) % p) - kp
		int rem = (i+1) % p;
		int b = as[i] - rem;
		int a = b - ((i+1)/p)*p;

		// Get first a + kp at least "low"
		if (a < low) {
			int diff = low - a + (p-1);
			a += p * (diff / p);
		}

		if (b >= a) {
			if (a - low < m) ++can[a - low];
			if (b + p - low < m) --can[b + p - low];
		}
	}
	for (int i = 0; i+p < m; ++i) {
		can[i+p] += can[i];
	}

	int res = 0;
	for (int i = 0; i < m; ++i) res += (can[i] == 0);

	cout << res << '\n';
	for (int i = 0; i < m; ++i) {
		if (can[i] == 0) cout << low + i << ' ';
	}
	cout << '\n';
}