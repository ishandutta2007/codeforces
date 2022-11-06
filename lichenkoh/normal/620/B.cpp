#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
ll g[10]= {6,2,5,5,4,5,6,3,7,6};
int main() {
	ios_base::sync_with_stdio(false);
	ll a,b; cin >> a >> b;
	ll ans = 0;
	for (ll x = a; x <= b; x++) {
		ll y = x;
		while(y>0) {
			ll d = y%10;
			ans += g[d];
			y /= 10;
		}
	}
	cout << ans << endl;
}