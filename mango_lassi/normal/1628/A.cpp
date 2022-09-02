#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> as(n), cou(n+1, 0), cur(n+1, 0);
	for (int& a : as) {
		cin >> a;
		++cou[a];
	}

	vector<int> res;
	for (int i = 0, c = 0; i < n; ++i) {
		--cou[as[i]];
		++cur[as[i]];
		while(cur[c]) ++c;
		if (cou[c] == 0) {
			res.push_back(c);
			for(; c; --c) cur[c] = 0;
			cur[0] = 0;
		}
	}

	cout << res.size() << '\n';
	for (int v : res) cout << v << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}