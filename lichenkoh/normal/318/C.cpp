#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
int main() {
	ll x,y,m;
	cin >> x;
	cin >> y;
	cin >> m;
	if (x > y) {
		ll temp = x;
		x = y;
		y = temp;
	}
	if (y >= m) {
		cout << 0 << endl;
		return 0;
	}
	if (x <= 0 && y <= 0 && y < m) {
		cout << -1 << endl;
		return 0;
	}
	ll ans = 0;
	if (x > y) {
		ll temp = x;
		x = y;
		y = temp;
	}
	if (x < 0 && y > 0) {
		ll steps = (y-x)/y;
		x = x + steps*y;
		ans += steps;
	}
	while(y < m)
	{
		if (x > y) {
			ll temp = x;
			x = y;
			y = temp;
		}
		x = x + y;
		ans++;
		if (x >= m) {
			break;
		}
	}
	cout << ans << endl;
	return 0;
}