#include <bits/stdc++.h>
#include <complex>
#include <assert.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
int main() {
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	set<ll> x,y;
	for (ll i = 0; i < n; i++) {
		ll p,q;
		cin >> p; cin >> q;
		x.insert(p);
		y.insert(q);
	}
	if (x.size() == 2 && y.size() == 2) {
		ll x1 = *(x.begin());
		ll x2 = *(++x.begin());
		ll y1 = *(y.begin());
		ll y2 = *(++y.begin());
		ll ans = abs((x2 - x1) * (y2-y1));
		cout << ans << endl;
	}
	else {
		cout << -1 << endl;
	}

}