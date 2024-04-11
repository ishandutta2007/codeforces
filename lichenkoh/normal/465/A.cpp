#include <iostream>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		if (s[i] == '1') {
			ans++;
		}
		else {
			ans++;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}