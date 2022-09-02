#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int i, vector<int>& ans, vector<int>& seen, vector<int>& act, const vector<int>& cyc, const vector<int>& p) {
	seen[i] = 1;
	if (i > 0 && !act[cyc[i - 1]]) {
		act[cyc[i - 1]] = 1;
		dfs(i - 1, ans, seen, act, cyc, p);
	}
	if (i + 1 < cyc.size() && !act[cyc[i + 1]]) {
		act[cyc[i + 1]] = 1;
		dfs(i + 1, ans, seen, act, cyc, p);
	}
	ans.push_back(i);
	if (! seen[p[i]]) dfs(p[i], ans, seen, act, cyc, p);
}

void solve() {
	int n;
	cin >> n;

	vector<int> ps(n);
	for (int& p : ps) {
		cin >> p;
		--p;
	}

	// Lexicographically minimal answer always starts with 1

	// Answer = 2 * (-1 + number of cycles in p)
	// Clear lower bound, and easily achievable

	int cc = 0;
	vector<int> cyc(n, -1);
	for (int i = 0; i < n; ++i) {
		if (cyc[i] == -1) {
			for (int j = i; cyc[j] == -1; j = ps[j]) cyc[j] = cc;
			++cc;
		}
	}

	vector<int> ans, act(cc, 0), seen(n, 0);
	act[0] = 1;
	dfs(0, ans, seen, act, cyc, ps);
	reverse(ans.begin(), ans.end());

	for (int i : ans) cout << i + 1 << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}