#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9 + 7;

int minSwaps(vector<int> ini, const vector<int>& res) {
	int n = ini.size();
	vector<int> tar(n);
	for (int i = 0; i < n; ++i) tar[res[i]] = i;

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		while (res[i] != ini[i]) {
			int t = tar[ini[i]];
			swap(ini[i], ini[t]);
			++ans;
		}
	}
	return ans;
}

void solve() {
	int n, m;
	cin >> n >> m; // m <= n/3
	
	// 2m change place -> at least n - 2m >= n/3 have to match
	// -> at most 3 permutations to try

	vector<int> match(n, 0), as(n);
	for (int i = 0; i < n; ++i) {
		cin >> as[i];
		--as[i];

		// Shift of t -> i at position (i + t) % n
		int s = (i - as[i] + n) % n;
		++match[s];
	}

	vector<int> res;
	for (int s = 0; s < n; ++s) {
		if (match[s] >= n - 2*m) {
			vector<int> perm(n);
			for (int i = 0; i < n; ++i) perm[i] = (i + n - s) % n;
			int ops = minSwaps(perm, as);
			if (ops <= m) res.push_back(s);
		}
	}

	cout << res.size();
	for (int& s : res) cout << ' ' << s;
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}