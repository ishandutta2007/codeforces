#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
int main() {
	ll a = 0;
	ll in = 0;
	ll f = 0;
	ll n = 0;
	cin >> n;
	string s;
	cin >> s;
	for (ll i = 0; i < n; i++) {
		if (s[i] == 'A') {
			a++;
		}
		else if (s[i] == 'I') {
			in++;
		}
		else if (s[i] == 'F') {
			f++;
		}
		else {
			//assert(false);
		}
	}
	ll ans = -1;
	if (in == 1) {
		ans = 1;
	}
	else if (in == 0) {
		ans = a+in;
	}
	else{
		//assert(in >= 2);
		ans = 0;
	}
	cout << ans << endl;
}