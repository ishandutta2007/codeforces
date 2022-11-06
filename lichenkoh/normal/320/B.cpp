#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
ll e[101];
vector<ll> g[101];
bool dfs(ll v, ll wanted) {
	if (v == wanted) {
		return true;
	}
	e[v] = true;
	for (vector<ll>::iterator it = g[v].begin(); it != g[v].end(); ++it) {
		ll w = *it;
		if (e[w] == false) {
			bool res = dfs(w,wanted);
			if (res == true) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	
	ll d[101][2];
	ll n;
	cin >> n;
	ll ind = 1;
	for (ll i = 0; i < n; i++) {
		ll c;
		cin >> c;
		if (c == 1) {
			ll x,y;
			cin >> x;
			cin >> y;
			d[ind][0] = x;
			d[ind][1] = y;
			for (ll j = 1; j < ind; j++) {
				ll a,b;
				a = d[j][0];
				b = d[j][1];
				if ((x < a && a < y) || (x < b && b < y)) {
					g[j].push_back(ind);
				}
				if ((a < x && x < b) || (a < y && y < b)) {
					g[ind].push_back(j);
				}
			}
			ind++;
		}
		if (c == 2) {
			ll x,y;
			cin >> x;
			cin >> y;
			for (ll j = 0; j < 101; j++) {
				e[j] = false;
			}
			ll res = dfs(x,y);
			if (res) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}