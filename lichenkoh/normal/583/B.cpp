#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll *a;
ll *b;
ll n;
ll f() {
	ll d = 1;
	ll x = 0;
	ll c = 0;
	ll ans = 0;
	while(1) {
		if (d == 1) {
			for (; x < n; x++) {
				if (a[x] <= c) {
					c += b[x];
					b[x] = 0;
				}
				if (c >= n) return ans;
			}
		}
		else {
			for (; x >= 0; x--) {
				if (a[x] <= c) {
					c += b[x];
					b[x] = 0;
				}
				if (c >= n) return ans;
			}
		}
		d *= -1;
		ans++;
	}
	assert(false);
}

int main() {
	cin >> n;
	a = new ll[n];
	b = new ll[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = 1;
	}
	ll ans1 = f();
	cout << ans1 << endl;
	return 0;

}