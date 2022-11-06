#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007LL
#define UNDEF -1LL
#define PB push_back
#define MP make_pair

int main() {
	ios_base::sync_with_stdio(false);
	ll n; cin >> n;
	ll *a = new ll[n+1];
	ll *hi = new ll[n+1];
	ll *lo = new ll[n+1];
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ll q = a[n];
	for (ll i = n; i >= 1; i--) {
		q = min(q, a[i]);
		lo[i] = q;
	}
	ll r = a[1];
	for (ll i = 1; i <= n; i++) {
		r = max(r, a[i]);
		hi[i] = r;
	}
	ll ans = 1;
	for (ll i = 1; i < n; i++) {
		if (hi[i] <= lo[i+1]) {
			ans++;
		}
	}
	cout << ans << endl;
}