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
	ll n, k;
	cin >> n; cin >> k;
	ll *s = new ll[n+1];
	for (ll i = 1; i <= n; i++) {
		cin >> s[i];
	}
	ll ans = s[n];
	ll x = 2*(n-k);
	if (x >= 2) {
		for (ll i = 0; i < x/2; i++) {
			ll cand = s[1+i] + s[x-i];
			ans = max(ans, cand);
		}
	}
	cout << ans << endl;
}