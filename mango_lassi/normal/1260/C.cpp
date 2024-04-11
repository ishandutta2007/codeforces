#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ll a, b, k;
		cin >> a >> b >> k;
		ll d = gcd(a, b);
		a /= d;
		b /= d;

		if (a < b) swap(a, b);
		if (k == 1 || (a-2) / b + 1 >= k) cout << "REBEL\n";
		else cout << "OBEY\n";
	}
}