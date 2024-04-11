#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, k;
	cin >> n >> k;

	// k = n + 1?
	// no two intervals can intersect
	// Loop left to right until some colour has appeared twice
	// Make interval for that colour, delete the prefix
	// Amount of appearances of every other colour drops by at most one!

	// Generalisation: loop left to right, whenever you get two of a colour, make interval for it and increment
	//	counter for all colour appearances. When counter hits ceil(n / (k - 1)), delete appearance

	// fail IFF ceil(n / (k - 1)) * (k - 1) <= n - 1, which NEVER HOLDS!

	int cap = (n + (k - 2)) / (k - 1);

	vector<pair<int, int>> res(n, make_pair(-1, -1));
	vector<pair<int, int>> cou(n, make_pair(-1, 0));
	for (int i = 0; i < n*k; ++i) {
		int c;
		cin >> c;
		--c;
		if (cou[c].first != -1 && res[c].first == -1) {
			res[c] = {cou[c].first, i};
			for (int c2 = 0; c2 < n; ++c2) {
				++cou[c2].second;
				if (cou[c2].second >= cap) {
					cou[c2] = {-1, 0};
				}
			}
		} else {
			cou[c] = {i, 0};
		}
	}
	for (int i = 0; i < n; ++i) assert(res[i].first != -1);
	for (auto pr : res) cout << pr.first + 1 << ' ' << pr.second + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}