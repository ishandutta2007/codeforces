#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <assert.h>
using namespace std;
typedef long long ll;
int main() {
	ll n,g,b,d;
	scanf("%I64d %I64d %I64d",&d,&g,&n);
	b=g;
	pair<ll,ll> *a = new pair<ll,ll>[n+1];
	for (ll i = 0; i < n; i++) {
		ll xi,pi;
		scanf("%I64d %I64d",&xi,&pi);
		a[i] = make_pair(xi,pi);
	}
	a[n] = make_pair(d,0);
	n++;
	sort(a,a+n);
	ll x = b;
	ll ans = 0;
	map<ll,ll> m;
	for (ll i = 0; i < n; i++) {
		ll dest = a[i].first;
		for (map<ll,ll>::iterator it = m.begin(); it != m.end();) {
			if (x >= dest) break; // no need to buy
			ll price = it->first;
			ll avail = (it->second - x);
			if (avail > 0) {
				ll add = min((dest-x), avail);
				ans += add*price;
				x += add;
				++it;
			}
			else {
				map<ll,ll>::iterator oldit = it;
				++it;
				m.erase(oldit);
			}
		}
		if (x < dest) {
			ans = -1;
			break;
		}
		ll price = a[i].second;
		ll potential = dest + g;
		m[price] = potential;
	}
	printf("%I64d\n",ans);
	return 0;
}