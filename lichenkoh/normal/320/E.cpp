#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define ll long long
#define sll long long
#define INF 9223372036854775807LL
#define MINF -9223372036854775807LL

double intx(ll a, ll b, ll c, ll d) {
	return ((double)(d-b)) / ((double)(a-c));
}


int main() {
	ll n;
	cin >> n;
	ll *a = new ll[n+1];
	ll *b = new ll[n+1];
	ll m = 0;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		m += b[i];
	}
	
	for (ll i = 1; i <= n; i++) {
		cin >> b[i];
	}
	ll oldbn = b[n];
	for (ll i = 1; i <= n; i++) {
		b[i] = b[i] - b[n];
	}
	ll *c = new ll[n+1];
	ll *s = new ll[n+1];
	pair<double, ll> *p = new pair<double,ll>[n+1];
	double *q = new double[n+1];
	ll psize = 1;
	p[0] = make_pair(MINF,1);
	q[1] = MINF;
	c[1] = 0;
	for (ll i = 1; i <= n; i++) {
		s[i] = b[1] - b[i];
	}
	ll lastpos = 0;
	for (ll t = 2; t <= n; t++) {
		//for (ll j = 0; j < psize; j++) {
		//	cout << "P:" << p[j].first << ":" << p[j].second << endl;
		//}
		ll line = 1;
		for (ll i = lastpos; i < psize; i++) {
			if (a[t] > p[i].first) {
				line = p[i].second;
				lastpos = i;
			}
		}
		//cout << "t:" << t << " using line i :" << line << endl;
		sll savings = max(s[line]*a[t] - c[line], 0LL);
		// Cost = Base Cost - Savings
		sll cost = a[t] * b[1] - savings;
		c[t] = cost;
		assert(cost >= 0LL);
		//cout << "t:" << t << " psize:" << psize << endl;
		for (ll it = psize-1; it >= 0; --it) {
			ll i = p[it].second;
			double intersect = intx(s[t],-c[t],s[i],-c[i]);
			//cout << "INTX:" << intersect << ":" << q[i] << endl;
			if (intersect < q[i]) {
				psize--;
			}
			else {
				q[t] = intersect;
				psize++;
				p[psize-1] = (make_pair(intersect,t));
				lastpos = min(lastpos, psize-1);
				break;
			}
		}
		//cout << "t:" << t << " c[t]:" << cost << " s[t]" << s[t] << endl;
	}
	ll ans = c[n];
	ans += m * oldbn;
	cout << ans << endl;
	return 0;
}