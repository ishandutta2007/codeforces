#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> pws;
vector<pair<int, int>> res;

void solve(vector<int>& vals) {
	while(! vals.empty()) {
		if (vals.size() <= 2) {
			for (int v : vals) pws.push_back(v);
			return;
		} else {
			int n = vals.size(), h = 1;
			while(h < n) h *= 2;
			int k = h/2 - 1;

			if (h == n) {
				pws.push_back(vals.back());
				vals.pop_back();
				--n;
			}

			vector<int> big;
			pws.push_back(vals[k]);
			for (int i = 1; i + k < n; ++i) {
				int v0 = vals[k + i];
				int v1 = vals[k - i];
				res.emplace_back(v0, v1);
				pws.push_back(v0 + v1);
				big.push_back(v0 - v1);
			}
			solve(big);

			cerr << n << ' ' << n - (1 + 2*(n-k-1)) << endl;
			vals.resize(n - (1 + 2*(n-k-1)));
		}
	}
}

void solve() {
	int n;
	cin >> n;

	if (n == 1) {
		cout << 0 << '\n';
	} else if (n == 2) {
		cout << -1 << '\n';
	} else {
		int h = 1, k = 0;
		while(h < n) {
			h <<= 1;
			++k;
		}

		if (n == h) pws.push_back(h);
		vector<int> vals(min(n, h-1));
		for (int i = 0; i < vals.size(); ++i) vals[i] = i + 1;
		solve(vals);

		// Handle pws
		sort(pws.begin(), pws.end());
		
		for (int i = 0; i < pws.size(); ++i) {
			if (pws[i] < h && i + 1 < pws.size() && pws[i+1] == pws[i]) {
				res.emplace_back(pws[i], pws[i]);
				pws[i+1] *= 2;
				pws[i] = 0;
				break;
			}
		}
		sort(pws.begin(), pws.end());

		for (int i = 1; i < pws.size(); ++i) {
			while(pws[i] < h) {
				res.emplace_back(pws[i], 0);
				res.emplace_back(pws[i], pws[i]);
				pws[i] *= 2;
			}
		}
		res.emplace_back(0, h);

		cout << res.size() << '\n';
		for (auto pr : res) cout << pr.first << ' ' << pr.second << '\n';

		pws.clear();
		res.clear();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}