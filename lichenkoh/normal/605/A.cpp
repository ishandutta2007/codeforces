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
	ll n; cin >> n;
	ll *p = new ll[n+4];
	ll *a = new ll[n+4];
	for (ll i = 0; i < (n+4); i++) {
		a[i] = 0;
	}
	for (ll i = 0; i < n; i++) {
		cin >> p[i];
	}
	ll best = 0;
	for (ll i = 0; i < n; i++) {
		ll x = p[i];
		a[x] = a[x-1]+1;
		best = max(best, a[x]);
	}
	ll ans = n - best;
	cout << ans << endl;
}