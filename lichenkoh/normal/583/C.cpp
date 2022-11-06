#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	map<ll,ll, greater<ll> > h;
	for (ll i = 0; i < n*n; i++) {
		ll x;
		cin >> x;
		if (h.find(x) == h.end()) {
			h[x] = 1;
		}
		else {
			h[x]++;
		}
	}
	vector<ll> v;
	for (ll i = 0; i < n; i++) {
		ll x = (h.begin())->first;
		for (vector<ll>::iterator it = v.begin(); it != v.end(); ++it) {
			ll g = __gcd(x, *it);
			h[g] = h[g] - 2;
			if (h[g] <= 0) {
				h.erase(g);
			}
		}
		h[x]--;
		if (h[x] == 0) {
			h.erase(x);
		}
		v.push_back(x);
	}
	bool outed = false;
	for (vector<ll>::iterator it = v.begin(); it != v.end(); ++it) {
		if (outed) cout << " ";
		cout << *it;
		outed = true;
	}
	cout << endl;
}