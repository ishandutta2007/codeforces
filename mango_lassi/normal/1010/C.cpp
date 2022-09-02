#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int n, k;
	cin >> n >> k;

	int d = k;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		d = gcd(a, d);
	}

	int res = k / d;
	cout << res << '\n';
	for (int i = 0; i < k; i += d) {
		cout << i << ' ';
	}
	cout << '\n';
}