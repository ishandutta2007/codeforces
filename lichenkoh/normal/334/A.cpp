#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll unsigned long long
int main() {
	ll n;
	cin >> n;
	ll c = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n/2; j++) {
			cout << c+1 << " " << n*n-c << " ";
			c++;
		}
		cout << endl;
	}
	return 0;
}