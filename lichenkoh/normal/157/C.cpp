#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <array>
#include <iomanip>
#define ll long long
#define PI atan(1)*4
using namespace std;
int main() {
	string s,u;
	cin >> s;
	cin >> u;
	ll sl = s.length();
	ll ul = u.length();
	ll m = ul + sl + ul;
	char *a = new char[m];
	for (ll i = 0; i < m; i++) {
		a[i] = 0;
	}
	for (ll i = 0; i < sl; i++) {
		a[ul+i] = s[i];
	}
	ll small = 999999999999999;
	//ll off = 0;
	for (ll x = 0; x < ul+sl; x++) {
		ll score = 0;
		for (ll i = 0; i < ul; i++) {
			if (a[x+i] != u[i]) {
				score++;
			}
		}
		if (score < small) {
			small = score;
			//off = x;
		}
	}
	cout << small << endl;
	return 0;
}