#include <iostream>
#include <assert.h>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
	string s;
	cin >> s;
	ll n = s.length();
	ll *a = new ll[n+1];
	a[0] = 0;
	for (ll i = 1; i < n; i++) {
		if (s[i-1] == s[i]) {
			a[i] = a[i-1] + 1;
		}
		else {
			a[i] = a[i-1];
		}
	}
	s[n] = s[n-1];
	ll m;
	cin >> m;
	for (ll i = 0; i < m; i++) {
		ll l,r;
		cin >> l;
		cin >> r;
		cout << a[r-1]-a[l-1] << endl;
	} 
	return 0;
}