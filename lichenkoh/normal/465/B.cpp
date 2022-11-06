#include <iostream>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
	ll n;
	cin >> n;
	ll *a = new ll[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll ans = 0;
	bool first = true;
	for (ll i = 0; i < n; i++) {
		if (a[i] == 1) {
			if (first) {
				ans++;
			}
			else {
				if (a[i-1]  == 1) ans++;
				if (a[i-1] == 0) ans += 2;
			}
			first = false;
		}
	}
	cout << ans << endl;
}