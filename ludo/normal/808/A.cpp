#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ll x;
	cin >> x;
	ll pow10 = 1;
	while (10 * pow10 <= x) {
		pow10 *= 10;
	}
	// ll y = x + (pow10 + 1 - ((x + 1) % pow10));
	ll y = x + pow10 - (x % pow10);
	cerr << y << endl;
	cout << (y - x) << endl;
	return 0;
}