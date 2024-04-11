#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll unsigned long long
#define INF 1844674407370955115ULL
int main() {
	ll n,m,kwant;
	cin >> n;
	cin >> m;
	cin >> kwant;
	ll d[315][315];
	ll c[315][315];
	for (ll i = 0; i < 315; i++) {
		for (ll j = 0; j < 315; j++) {
			c[i][j] = INF;
			d[i][j] = INF;
		}
	} 
	for (ll i = 0; i < m; i++) {
		ll l,r,cost;
		cin >> l;
		cin >> r;
		cin >> cost;
		c[l][r] = min(c[l][r],cost);
	}
	for (ll l = 1; l <= n; l++) {
		for (ll r = n; r >= l; r--) {
			c[l][r] = min(c[l][r], min(c[l-1][r],c[l][r+1]));
			//cout << l << ":" << r << ":" <<c[l][r] << endl;
		}
	}
	for (ll x = 0; x <= n; x++) {
		d[x][0] = 0;
	}
	for (ll k = 1; k <= n; k++) {
		for (ll x = 1; x <= n; x++) {
			d[x][k] = min(d[x][k], d[x-1][k]);
			for (ll y = 0; y < x; y++) {
				if (d[y][k-(x-y)] != INF && c[y+1][x] != INF) {
					d[x][k] = min(d[x][k],d[y][k-(x-y)]+c[y+1][x]);
				}
			}
			//cout << x << ":" << k << ":" << d[x][k] << endl;
		}
	}
	ll ans = INF;
	for (ll x = 1; x <= n; x++) {
		for (ll k = kwant; k <= n; k++) {
			ans = min(ans,d[x][k]);
		}
	}
	if (ans == INF) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}
	return 0;

}