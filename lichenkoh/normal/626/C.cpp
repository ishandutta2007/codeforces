#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl "\n"
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
bool f(ll n, ll x, ll y) {
	ll c=n/6;
	ll a=n/2 - c;
	ll b=n/3 - c;
	ll xt = max(0LL,x-a);
	ll yt = max(0LL,y-b);
	if (xt+yt<=c) return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	ll x,y; cin >> x >> y;
	ll imin=0; ll imax=(ll)1e9;
	while (imin<imax) {
		ll imid = imin+(imax-imin)/2;
		if (!f(imid,x,y)) {
			imin=imid+1;
		}
		else {
			imax=imid;
		}
	}
	ll ans=imin;
	cout << ans << endl;
}