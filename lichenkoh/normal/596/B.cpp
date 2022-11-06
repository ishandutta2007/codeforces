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
	ll s = 0;
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		ll x; cin >> x;
		ans += abs(x-s);
		s = x;
	}
	cout << ans << endl;
}