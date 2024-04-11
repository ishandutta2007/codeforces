#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
const ll MOD = 998244353;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
	int n;
	cin >> n;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;
	
	// Special case 2: one C after the P
	// Special case 3: one P before the C

	vector<ll> prefs(n+1, 0);
	for (int i = 1; i <= n; ++i) prefs[i] = prefs[i-1] + as[i-1];

	ll res = 0;

	// Special case 1: P at start, C at end
	for (int i = 1; i + 2 <= n; ++i) {
		if (prefs[i] > prefs[n] - prefs[i]) ++res;
	}
	// cerr << "Add from special case: " << res << '\n';

	// All other cases
	for (int j = 0; j <= 1; ++j) {
		ll add = 0, sum = 0;
		Tree<pair<ll, int>> vals;
		
		if ((n ^ j) & 1) vals.insert(make_pair(0, n));
		
		for (int i = n-1; i >= 0; --i) {
			add += ((i ^ j) & 1) ? as[i] : -as[i];
			sum += as[i];
			if ((i ^ j) & 1) {
				vals.insert(make_pair(sum - add, i));
				
				// Add case where we have one C at the end (over P)
				if (i < n-2) {
					vals.insert(make_pair(sum - add - 2*as[n-1], i));
				}

				ll cou = (int)vals.size() - vals.order_of_key(make_pair(prefs[i] + 1 - add, -1));
				res = (res + cou) % MOD;
				// cerr << "Add at " << i << ' ' << j << ": " << cou << '\n';

				// Add case where we have one P at the start
				if (i >= 3) {
					cou = (int)vals.size() - vals.order_of_key(make_pair((prefs[i] - 2*as[0]) + 1 - add, -1));
					// cerr << "P at start " << i << ": " << cou << '\n';
					res = (res + cou) % MOD;
				}
			}
		}
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}