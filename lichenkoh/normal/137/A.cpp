#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <array>
#include <iomanip>
#define ll unsigned long long
#define PI atan(1)*4
using namespace std;
int main() {
	string s;
	cin >> s;
	char current = 0;
	ll ans = 0;
	ll carry = 0;
	for (ll i = 0; i < s.length(); i++) {
		if (current==0) {
			current = s[0];
		}
		if (carry >= 5) {
			current = s[i];
			carry = 0;
			ans++;
		}
		if (current == s[i]) {
			carry++;
		}
		else {
			ans++;
			carry = 1;
			current = s[i];
		}
	}
	if (carry > 0) {
		ans++;
	}
	cout << ans << endl;
	return 0;
}