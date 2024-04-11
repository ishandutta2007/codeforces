#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		ll a, b, k;
		cin >> a >> b >> k;
		cout << a * ((k+1)/2) - b * (k/2) << '\n';
	}
}