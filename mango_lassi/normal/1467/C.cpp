#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18 + 7;

void solve() {
	array<int, 3> n;
	cin >> n[0] >> n[1] >> n[2];
	
	// Option 1: one pile has only negative numbers
	// Option 2: you choose two negative numbers from different piles

	ll sum = 0;
	ll res = INF;
	array<vector<ll>, 3> vecs;
	for (int j = 0; j < 3; ++j) {
		vecs[j].resize(n[j]);

		ll off = 0;
		for (int i = 0; i < n[j]; ++i) {
			cin >> vecs[j][i];
			off += vecs[j][i];
			sum += vecs[j][i];
		}
		res = min(res, off);
		sort(vecs[j].begin(), vecs[j].end());
	}
	res = min(res, vecs[0][0] + vecs[1][0]);
	res = min(res, vecs[1][0] + vecs[2][0]);
	res = min(res, vecs[2][0] + vecs[0][0]);

	cout << sum - 2*res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}