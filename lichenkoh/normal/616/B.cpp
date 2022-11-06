#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define INF 9223372368547758LL
int main() {
	ios_base::sync_with_stdio(false);
	ll n,m;
	cin >> n >> m;
	ll ans = -INF;
	for (ll i = 0; i < n; i++) {
		ll cand = INF;
		for (ll j = 0; j < m; j++) {
			ll x; cin >> x;
			cand = min(cand, x);
		}
		ans = max(ans, cand);
	}
	cout << ans << endl;
}