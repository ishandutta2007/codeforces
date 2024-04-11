#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long x;
	cin >> x;
	long long y = sqrt(x) + 2;
	while (y * y > x) --y;
	while (true) {
		if (x % y == 0 && __gcd(y, x / y) == 1) return cout << y << " " << x / y << endl, 0;
		--y;
	}
}