#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007LL
#define MP make_pair
#define PB push_back
#define INF 99999999999999999LL

int main() {
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll *a = new ll[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	bool g = false;
	ll l = -1; ll r = -1;
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		if (!g) {
			if (i != n && a[i] != a[i-1]) {
				l = i-1;
				g = true;
			}
		}
		else {
			if (i == n || a[i] == a[i-1]) {
				r = i-1;
				g = false;
				ll m = r-l-1;
				if (m%2 == 0) {
					ans = max(ans, m/2);
					assert(a[l] != a[r]);
					for (ll i = 1; i <= m/2; i++) {
						a[l+i] = a[l];
						a[r-i] = a[r];
					}
				}
				else {
					ans = max(ans, (m+1)/2);
					assert(a[l] == a[r]);
					for (ll i = l+1; i < r; i++) {
						a[i] = a[l];
					}
				}
			}
		}
	}
	cout << ans << endl;
	for (ll i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}