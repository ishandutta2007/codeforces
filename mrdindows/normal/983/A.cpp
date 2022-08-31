#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	while (n--) {
		long long p, q, b;
		cin >> p >> q >> b;
		long long g = gcd(p, q);
		q /= g;
		b = gcd(q, b);
		while (b != 1) {
			q /= b;
			b = gcd(q, b);
		}
		if (q == 1)
			cout << "Finite\n";
		else
			cout << "Infinite\n";
	}
	return 0;
}