#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
ll h[2000];
int main() {
	ios_base::sync_with_stdio(false);
	ll n,s; cin >> n >> s;
	for (ll i = 0; i < 2000; i++) {
		h[i] = -1;
	}
	for (ll i = 0; i < n; i++) {
		ll f,t; cin >> f >> t;
		h[f] = max(h[f], t);
	}
	ll t = 0;
	for (ll f = s; f >= 1; f--) {
		if (h[f] != -1) {
			t = max(t, h[f]);
		}
		t++;
	}
	cout << t << "\n";
}