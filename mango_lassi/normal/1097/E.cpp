#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;
const int N = (int)1e5;

int vals[N+1];
bool used[N];
vector<int> seq[N+1];
int nxt[N];

void solve() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> vals[i];
	for (int i = 0; i < n; ++i) used[i] = false;
	vals[n] = n+1;

	// Find at every pos the longest increasing seq
	// starting from it. If some of them has length S,
	// pick it and repeat. Otherwise, divide pos's into
	// groups by how long the longest sequence starting
	// from that pos is. These groups are decreasing,
	// and there's at most S-1 of them.

	// Worst case:
	// 1 3 2 6 5 4 10 9 8 7
	// Required number rises by 1 at every triangle number.

	// Which S should you pick?
	// With n = Tx + k remaining, (Tx x'th triangle number)
	// must have S-1 <= x, and S >= k. Setting S = x+1 works.
	
	vector<vector<int>> res;
	seq[0].push_back(n);
	
	int x = 0; // Amount needed to solve
	while((x+1)*(x+2)/2 <= n) ++x;
	for (; x > 0; --x) {
		for (int i = 1; i <= n; ++i) {
			seq[i].clear();
			seq[i].shrink_to_fit();
		}

		int h = 0;
		for (int i = n-1; i >= 0; --i) {
			if (used[i]) continue;
			int low = 1;
			int high = h+1;
			while(low != high) {
				int mid = (low + high + 1) >> 1;
				if (vals[seq[mid-1].back()] >= vals[i]) {
					low = mid;
				} else {
					high = mid - 1;
				}
			}
			seq[low].push_back(i);
			nxt[i] = seq[low-1].back();
			if (! seq[h+1].empty()) ++h;
		}
		if (h >= x+1) {
			// We find one of length > x \implies > k
			vector<int> add(h);
			int i = seq[h].back();
			for (int j = 0; j < h; ++j) {
				add[j] = i;
				used[i] = true;
				i = nxt[i];
			}
			res.push_back(add);
		} else {
			// We use exactly h, h <= x
			for (int i = 1; i <= h; ++i) {
				reverse(seq[i].begin(), seq[i].end());
				res.push_back(seq[i]);
			}
			break;
		}
	}

	cout << res.size() << '\n';
	for (auto& vec : res) {
		cout << vec.size();
		for (auto i : vec) cout << ' ' << vals[i];
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		solve();
	}
}