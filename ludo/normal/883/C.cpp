#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1e18;
ll f, T, t0, a1, t1, p1, a2, t2, p2;

ll solve1D(ll red, ll tred, ll load, ll cost)
{
	// find x s.t. x * red >= tred
	ll x = (tred + red - 1) / red;
	if (x > f) return -1;
	ll cx = (x + load - 1) / load;
	return cx * cost;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// cerr << boolalpha;
	(cout << fixed).precision(20);

	cin >> f >> T >> t0;
	cin >> a1 >> t1 >> p1;
	cin >> a2 >> t2 >> p2;

	ll dT = f * t0 - T;
	ll dt1 = t0 - t1;
	ll dt2 = t0 - t2;

	// cerr << "SUCH THAT y * " << dt1 << " + z * " << dt2 << " >= " << dT << endl;
	// optimal to use normal package:
	if (dT <= 0) { cout << 0 << endl; return 0; }
	if (dt1 <= 0 && dt2 <= 0) { cout << -1 << endl; return 0; }
	if (dt1 <= 0) { cout << solve1D(dt2, dT, a2, p2) << endl; return 0; }
	if (dt2 <= 0) { cout << solve1D(dt1, dT, a1, p1) << endl; return 0; }


	// cerr << "MIN: " << p1 << " * (y/" << a1 << ") + " << p2 << " * (z/" << a2 << ")" << endl;
	// cerr << "SUCH THAT y * " << dt1 << " + z * " << dt2 << " >= " << dT << endl;

	// dT, dt1, dt2 > 0
	ll ans = INF;
	for (ll y = 0; y <= f; y++) {
		ll tred = dT - y * dt1;
		ll z = tred < 0 ? 0 : ((tred + dt2 - 1) / dt2);
		if (y + z <= f) {
			ll cy = (y + a1 - 1) / a1;
			ll cz = (z + a2 - 1) / a2;
			ll cost = cy * p1 + cz * p2;
			if (cost < ans) ans = cost;
		}
	}
	if (ans == INF) ans = -1;
	cout << ans << endl;
	return 0;
}