#include <bits/stdc++.h>
#include <complex>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MOD 1000000007LL
#define PB push_back
#define UNDEF -1
int main() {
	ios_base::sync_with_stdio(false);
	ll n,m;
	cin >> n; cin >> m;
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			ll a,b; cin >> a; cin >> b;
			if (a == 1 || b == 1) {
				ans++;
			}
		}
	}
	cout << ans << endl;
}