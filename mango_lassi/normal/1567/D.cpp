#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	ll s;
	cin >> s >> n;

	int ind = 0, rem = n;
	vector<ll> ans(n, 0);
	for (ll mult10 = (ll)1e9; mult10 > 0; mult10 /= 10) {
		for (int j = 0; (mult10 <= s) && (rem - 1 <= s - mult10); ++j) {
			ans[ind] += mult10;
			s -= mult10;
			--rem;
			ind = (ind + 1) % n;
		}
	}
	for (ll& v : ans) cout << v << ' '; cout << '\n';

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}