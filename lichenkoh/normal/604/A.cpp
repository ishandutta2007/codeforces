#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
int main() {
	ios_base::sync_with_stdio(false);
	ll m[6], w[6];
	for (ll i = 1; i <= 5; i++) {
		cin >> m[i];
	}
	for (ll i = 1; i <= 5; i++) {
		cin >> w[i];
	}
	ll hs,hu; cin >> hs; cin >> hu;
	ll ans = 0;
	for (ll i = 1; i <= 5; i++) {
		ll x = i * 500;
		ll a = (x*3)/10;
		ll b = x - (x*m[i])/250 - 50*w[i];
		ll c = max(a,b);
		ans += c;
	}
	ll h = 100 * hs - 50 * hu;
	ans += h;
	cout << ans << endl;
}