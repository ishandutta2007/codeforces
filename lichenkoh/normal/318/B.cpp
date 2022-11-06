#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define SZ 1000010
#define ll long long
int main() {
	string s;
	ll *m = new ll[SZ];
	ll *h = new ll[SZ];
	cin >> s;
	string str2 ("metal");
	string str3 ("heavy");
	for (ll i = 0; i < SZ; i++) {
		m[i] = 0;
		h[i] = 0;
	}
	size_t found = s.find(str2);
	if (found == std::string::npos) {
	}
	else {
		m[found] = 1;
		while(1) {
			found = s.find(str2,found+1);
			if (found == std::string::npos) {
				break;
			}
			m[found] = 1;
		}
	}

	for (ll i = SZ-2; i >= 0; i--) {
		m[i] += m[i+1];
	}


	size_t found2 = s.find(str3);
	if (found2 == std::string::npos) {
	}
	else {
		h[found2] = 1;
		while(1) {
			found2 = s.find(str3,found2+1);
			if (found2 == std::string::npos) {
				break;
			}
			h[found2+5] = 1;
		}
	}
	ll ans = 0;
	for (ll i = 0; i < SZ-1; i++) {
		if (h[i] == 1) {
			ans += m[i];
		}
	}
	cout << ans << endl;


	return 0;
}