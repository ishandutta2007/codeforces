#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = (ll)1e18;
int main() {
	int n;
	cin >> n;

	set<ll> actives;
	actives.insert(-1);
	actives.insert(INF);
	ll low = -1;
	ll high = INF;

	ll res = 1;
	int between = 0;
	for (int i = 0; i < n; ++i) {
		string op;
		ll t;
		cin >> op >> t;
		
		if (op == "ACCEPT") {
			if (low < t && t < high) {
				res = (res * 2) % MOD; // Was the deleted one a SELL or a BUY
			} else if (t < low || high < t) {
				res = 0;
			}
			auto it = actives.find(t);
			--it;
			low = *it;
			++it;
			++it;
			high = *it;
			--it;
			actives.erase(it);
			between = 0;
		} else {
			actives.insert(t);
			if (low < t && t < high) {
				++between;
			}
		}
	}
	cout << (res * (between + 1)) % MOD << '\n';
}