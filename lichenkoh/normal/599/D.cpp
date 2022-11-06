#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MOD 1000000007LL
#define UNDEF -1LL
#define PB push_back
#define MP make_pair
#define THIRD 0.3333334
int main() {
	ios_base::sync_with_stdio(false);
	ll k; cin >> k;
	k = 6 * k;
	ld limd = pow(k, THIRD);
	ll lim = ceil(limd);
	set<pair<ll,ll> > ans;
	for (ll a = 0; a <= lim; a++) {
		if (k % (a+1) == 0) {
			ll t = k/(a+1);
			if (t % (a+2) == 0) {
				ll s = t/(a+2);
				ll x3 = s - 2*a;
				if (x3 > 0 && x3 % 3 == 0) {
					ll x = x3/3;
					ans.insert(MP(a+1, a+x));
					ans.insert(MP(a+x, a+1));
				}
			}
		}
	}
	ll sz = ans.size();
	printf("%I64d\n", sz);
	for (auto& y: ans) {
		printf("%I64d %I64d\n", y.first, y.second);
	}
}