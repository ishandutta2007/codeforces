#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	// Answer for x: maximum number of disjoint equal segments of length x

	// If there were no question marks, this can be solved by adding to the answer for each block of 0's or 1's
	// A block of length k adds floor(k/x) to the answer of x. We can just brute these.

	// It turns out we can similarly brute force the blocks when there are question marks!
	// Only segments, where the sum of the length of the segment and the lengths of the segments of question marks before and after it is at least x,
	// can contribute to the answer of x. There are at most O(n / x) of these -> O(n log n) algorithm.

	string str;
	cin >> str;

	// 1. Replace 1?...?1 or 0?...?0 with 11...11 or 00...00
	char pre = '1';
	for (int i = 0; i < n; ++i) {
		if (str[i] == '?' && i+1 < n && str[i+1] == pre) {
			for (int j = i; j >= 0 && str[j] == '?'; --j) str[j] = pre;
		} else if (str[i] != '?') pre = str[i];
	}

	// 2. Get lengths of segments
	//	Every odd index is segment of question marks, every off segment of 0 or 1, alternating
	vector<int> segs = {0};
	int cur = 0;
	char act = '?';
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] != act) {
			segs.push_back(cur);
			if (act != '?' && str[i] != '?') segs.push_back(0); // 0-length segment of ?
			act = str[i];
			cur = 0;
		}
		++cur;
	}
	segs.push_back(cur);
	if (act != '?') segs.push_back(0);
	int m = segs.size();

	// for (auto v : segs) cerr << v << ' '; cerr << '\n';

	// Solve
	vector<int> nxt(m, -1); // next segment that can still contribute
	for (int i = 0; i < m; i += 2) nxt[i] = i+2;

	for (int x = 1; x <= n; ++x) {
		int add = 0; // How much remains of previous ?-segment
		int res = 0; // Answer for this x

		for (int i = 0; i < m; i = nxt[i]) {
			// Add contribution of current segment
			int len = add + segs[i] + segs[i+1];
			int k = len / x;
			res += k;
			add = min(segs[i+1], len - k * x);

			// cerr << x << ' ' << i << ' ' << add << '\n';

			// Update nxt[i]
			while(true) {
				int ni = nxt[i];
				if (ni >= m || segs[ni-1] + segs[ni] + segs[ni+1] >= x) break;
				else nxt[i] += 2;
			}
			if (nxt[i] > i+2) add = segs[nxt[i] - 1];
		}
		cout << res << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}