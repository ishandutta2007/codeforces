#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll a, b;
	cin >> a >> b;
	// gcd(a, a+1) = 1
	cout << "YES\n";
	for (ll i = a; i < b; i += 2) cout << i << ' ' << i+1 << '\n';
}