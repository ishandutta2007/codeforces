#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
	int t;
	cin >> t;
	
	for (int q = 0; q < t; ++q) {
		ll s, a, b, c;
		cin >> s >> a >> b >> c;
		cout << (s / (c*a)) * b + (s / (c)) << '\n';
	}
}