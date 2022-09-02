#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	ll x0 = 0; // Amount of energy after which more energy doesn't help
	ll x1 = 0; // Amount of energy after which 1 energy decreases time by 1
	ll x2 = 0; // Amount of energy after which 1 energy decreases time by 2
	ll x3 = 0; // Amount of energy after which 1 energy decreases time by 3
	ll x5 = 0; // Amount of energy after which 1 energy decreases time by 5
	ll bs = 0; // Time to finish with x0 energy
	
	vector<ll> lens(n);
	for (int i = 0; i < n; ++i) cin >> lens[i];
	string tps;
	cin >> tps;
	
	// Slope trick, done in a pretty dumb way
	for (int i = n-1; i >= 0; --i) {
		ll d = lens[i];
		bs += d;
		if (tps[i] == 'G') {
			// Passive change cost 2
			// Cap cost 5
			x0 += d;
			x1 += d;
			x2 = max(0ll, x2-d);
			x3 = max(0ll, x3-d);
			x5 = 0;
		} else if (tps[i] == 'W') {
			// Passive change cost 1
			// Cap cost 3
			x0 += d;
			x1 = max(0ll, x1-d);
			x2 = max(0ll, x2-d);
			x3 = 0;
			x5 = 0;
		} else {
			// Must fly
			x0 += d;
			x1 += d;
			x2 += d;
			x3 += d;
			x5 += d;
		}
	}
	if (x5 > 0) {
		cout << "-1\n";
	} else {
		// x5 = 0
		ll res = bs;
		res += 5 * (x3 - x5);
		res += 3 * (x2 - x3);
		res += 2 * (x1 - x2);
		res += 1 * (x0 - x1);
		cout << res << '\n';
	}
}