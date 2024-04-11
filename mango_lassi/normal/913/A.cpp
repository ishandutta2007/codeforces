#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll n, m;
	cin >> n >> m;
	if (n > 40) n = 40;
	cout << (m % (((ll)1)<<n)) << '\n';
}