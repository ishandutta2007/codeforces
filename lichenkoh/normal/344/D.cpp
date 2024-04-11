#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll unsigned long
int main() {
	string s;
	cin >> s;
	ll n = s.length();
	ll *t = new ll[n+100];
	ll count = 0;
	char prev = 0;
	ll j = 0;
	for (ll i = 0; i < n; i++) {
		if (s[i] == prev) {
			count++;
		}
		else {
			prev = s[i];
			t[j] = count % 2;
			j++;
			count = 1;
		}
	}
	t[j] = count % 2;
	ll tlen = j+1;
	ll ans = 0;
	for (ll i = 0; i < tlen; i++) {
		//cout << t[i] << endl;
		if (t[i] == 0) {
			ans *= -1;
		}
		else {
			ans += t[i];
		}
	}
	if (ans == 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}