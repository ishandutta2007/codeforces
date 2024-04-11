#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> as(n);
	for (int& a : as) {
		cin >> a;
		--a;
	}

	vector<bool> done(n, 0);
	vector<int> ins(n, 0), ss, ts;
	for (int i = 0; i < n; ++i) ++ins[as[i]];
	for (int i = 0; i < n; ++i) {
		if (ins[i] == 0) ss.push_back(i);
	}

	int res = n;
	for (int s : ss) {
		int t = s;
		while(true) {
			done[t] = 1;
			if (done[as[t]]) break;
			t = as[t];
		}
		ts.emplace_back(t);
		--res;
	}
	for (int i = 0; i < ss.size(); ++i) as[ts[i]] = ss[(i + 1) % ss.size()];

	cout << res << '\n';
	for (int i = 0; i < n; ++i) cout << as[i] + 1 << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}