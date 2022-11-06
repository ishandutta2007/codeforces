#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define INF 9000000009
ll *lefty,*righty,*val;
ll getlefty(ll x) {
	if (lefty[x] != x) {
		lefty[x] = getlefty(lefty[x]);
	}
	return lefty[x];
}
ll getrighty(ll x) {
	if (righty[x] != x) {
		righty[x] = getrighty(righty[x]);
	}
	return righty[x];
}
ll getval(ll x) {
	ll l = getlefty(x);
	return val[l];
}
void setval(ll x, ll v) {
	ll l = getlefty(x);
	val[l] = v;
}
int main() {
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll *a = new ll[n+2];
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[0] = -INF;
	a[n+1] = -INF;
	ll *ans = new ll[n+1];
	for (ll i = 0; i <= n; i++) {
		ans[i] = -INF;
	}
	lefty = new ll[n+2];
	righty = new ll[n+2];
	val = new ll[n+2];
	for (ll i = 0; i < n+2; i++) {
		lefty[i] = i;
		righty[i] = i;
		val[i] = a[i];
	}
	priority_queue<pair<ll,ll> > q;
	for (ll i = 1; i <= n; i++) {
		q.push(MP(a[i],i));
	}
	while(!q.empty()) {
		ll x = q.top().second;
		q.pop();
		ll l = getlefty(x)-1;
		ll r = getrighty(x)+1;
		ll size = r-l-1;
		ans[size] = max(a[x], ans[size]);
		ll candl = getval(l);
		ll candr = getval(r);
		if (candl > candr) {
			lefty[x] = l;
			righty[l] = x;
			setval(x,candl);
		}
		else {
			righty[x] = r;
			lefty[r] = x;
			setval(x,candr);
		}
	}
	ll maxseen = -1;
	for (ll i = n; i >= 1; i--) {
		maxseen = max(maxseen, ans[i]);
		ans[i] = maxseen;
	}
	for (ll i = 1; i <= n; i++) {
		cout << ans[i];
		if (i < n) {cout << " ";}
	}
	cout << endl;
}