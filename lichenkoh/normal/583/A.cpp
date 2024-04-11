#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
	ll n;
	cin >> n;
	bool *a = new bool[n+1];
	bool *b = new bool[n+1];
	for (ll i = 0; i <= n; i++) {
		a[i] = false;
		b[i] = false;
	}
	bool outed = false;
	for (ll i = 1; i <= n*n; i++) {
		ll h; ll v;
		cin >> h; cin >> v;
		if ((!a[h]) && (!b[v])) {
			a[h] = true;
			b[v] = true;
			if (outed) {
				cout << " ";
			}
			cout << i;
			outed = true;
		}
	}
	cout << endl;
}