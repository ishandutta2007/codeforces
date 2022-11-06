#include <bits/stdc++.h>
#include <assert.h>
#define PB push_back
#define MP make_pair
#define UNDEF -1
#define SZ 100000008
#define INF 9000000000LL
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
	ios_base::sync_with_stdio(false);
	ll n,q;
	cin >> n; cin >> q;
	ll *a = new ll[n];
	ll *l = new ll[n];
	ll *r = new ll[n];
	n--;
	{
		ll z;
		cin >> z;
		for (ll i = 0; i < n; i++) {
			ll y;
			cin >> y;
			a[i] = abs(y-z);
			z = y;
		}
	}
	{
		stack<pair<ll,ll> > s;
		s.push(MP(INF, -1LL));
		for (ll i = 0; i < n; i++) {
			ll x = a[i];
			// < to stop double counting duplicates
			while (s.top().first < x) {
				s.pop();
			}
			l[i] = s.top().second;
			//cout << i << "," << a[i] <<  ":" << l[i] << endl;
			s.push(MP(x, i));
		}
	}
	{
		stack<pair<ll,ll> > s;
		s.push(MP(INF, n));
		for (ll i = n-1; i >= 0; i--) {
			ll x = a[i];
			// no <=
			while (s.top().first <= x) {
				s.pop();
			}
			r[i] = s.top().second;
			//cout << i << "," << a[i] <<  ":" << r[i] << endl;
			s.push(MP(x, i));
		}
	}
	for (ll j = 0; j < q; j++) {
		ll left, right;
		cin >> left; cin >> right;
		left--;
		right-=2;
		ll ans = 0;
		for (ll k = left; k <= right; k++) {
			ll lo = max(l[k], left-1);
			ll hi = min(r[k], right+1);
			ll lower = k - lo;
			ll higher = hi - k;
			//printf("%d %d %d %d %d %d\n",
			//	k, lo, hi, lower, higher, a[k]);
			ans += lower * higher * a[k];
		}
		cout << ans << endl;
	}

}