#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18 + 7;

void solve() {
	int n;
	cin >> n;

	pair<ll, ll> fst = {INF, INF}, lst = {-INF, INF};
	ll bth = INF;
	
	for (int i = 0; i < n; ++i) {
		ll a, b, c;
		cin >> a >> b >> c;

		if (fst.first > a) {
			fst = {a, c};
			bth = INF;
		}
		if (fst.first == a) fst.second = min(fst.second, c);

		if (lst.first < b) {
			lst = {b, c};
			bth = INF;
		}
		if (lst.first == b) lst.second = min(lst.second, c);

		if (fst.first == a && lst.first == b) {
			bth = min(bth, c);
		}

		cout << min(fst.second + lst.second, bth) << '\n';
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}