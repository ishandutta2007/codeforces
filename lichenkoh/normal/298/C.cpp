#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll unsigned long long
int main() {
	string a,b;
	cin >> a;
	cin >> b;
	ll aone = 0;
	for (ll i = 0; i < a.length(); i++) {
		if (a[i] == '1') aone++;
	}
	if (aone % 2 != 0) {
		aone++;
	}
	ll bone = 0;
	for (ll i = 0; i < b.length(); i++) {
		if (b[i] == '1') bone++;
	}
	if (aone >= bone) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}