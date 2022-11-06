#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll unsigned long long


int main() {
	ll n,m;
	cin >> n;
	m = n;
	ll k = 1;
	while(1) {
		if (m == k) {
			cout << 1 << endl;
			return 0;
		}
		if (m % k != 0) {
			break;
		}
		else {
			k *= 3;
		}
	}
		cout << n/k + 1 << endl;

	return 0;
}