#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

// Find largest i with vec[i] <= x
int bins(const vector<ll>& vec, ll x) {
	int low = -1;
	int high = (int)vec.size() - 1;
	while(low != high) {
		int mid = (low + high + 1) >> 1;
		if (vec[mid] <= x) low = mid;
		else high = mid - 1;
	}
	return low;
}

ll getOffer(int j, const vector<ll>& xs, ll x1, ll x2) {
	if (j < 0 || j >= xs.size()) return INF;
	return abs(xs[j] - x1) + abs(xs[j] - x2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n, m, v;
	int cs, cl;
	cin >> n >> m >> cs >> cl >> v;

	vector<ll> stairs(cs);
	vector<ll> lifts(cl);
	for (int i = 0; i < cs; ++i) cin >> stairs[i];
	for (int i = 0; i < cl; ++i) cin >> lifts[i];

	int q;
	cin >> q;
	for (; q > 0; --q) {
		ll x1, y1, x2, y2;
		// cin >> x1 >> y1 >> x2 >> y2;
		cin >> y1 >> x1 >> y2 >> x2;
		
		ll dy = abs(y1 - y2);
		if (dy == 0) {
			cout << abs(x1 - x2) << '\n';
		} else {
			if (x2 < x1) swap(x1, x2);
			
			ll ans = INF;

			// Stairs
			int j = bins(stairs, x2);
			ans = min(ans, dy + getOffer(j, stairs, x1, x2));
			ans = min(ans, dy + getOffer(j+1, stairs, x1, x2));

			// Lift
			j = bins(lifts, x2);
			ans = min(ans, (dy+v-1)/v + getOffer(j, lifts, x1, x2));
			ans = min(ans, (dy+v-1)/v + getOffer(j+1, lifts, x1, x2));
			cout << ans << '\n';
		}
	}
}