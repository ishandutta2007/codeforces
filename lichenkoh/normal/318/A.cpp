#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll unsigned long long
int main() {
	ll n,k;
	cin >> n;
	cin >> k;
	ll ndiv2 = (n+1)/2;
	if (k <= ndiv2) {
		cout << 2*k-1 << endl;
	}
	else {
		cout << 2*(k-ndiv2) << endl;
	}
	return 0;
}