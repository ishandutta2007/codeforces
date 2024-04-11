#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int b;
		cin >> b;
		ll x = 0;
		ll y = 0;
		for (int j = 1; j <= b; j++) {
			ll c = 1ll << j;
			if (j < b / 2 || j == b) {
				x += c;
			} else {
				y += c;
			}
		}
		cout << abs(x - y) << "\n";
	}
}