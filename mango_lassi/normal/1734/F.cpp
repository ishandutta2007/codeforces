#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18 + 7;

map<pair<ll, ll>, ll> dp;

ll solve(ll n, ll m) {
	if (n == 0) return 0;

	auto it = dp.find(make_pair(n, m));
	if (it == dp.end()) {
		ll res = -1;
		if (n & 1) {
			res = (__builtin_parityll(n-1) == __builtin_parityll(n + m - 1)) + solve(n - 1, m);
		} else {
			if (m % 2 == 0) {
				res = 2 * solve(n/2, m/2);
			} else {
				res = n - solve(n/2, m/2) - solve(n/2, m/2 + 1);
			}
		}
		dp[make_pair(n, m)] = res;
		return res;
	} else {
		return (*it).second;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		ll n, m;
		cin >> m >> n;
		cout << n - solve(n, m) << '\n';
	}
}