#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
int main() {
	ll n,k;
	cin >> n;
	cin >> k;
	if (k >= (n*(n-1))/2) {
		cout << "no solution" << endl;
		return 0;
	}
	//ll y = 0;
	//ll delta = n;
	for (ll i = 0; i < n; i++) {
		cout << "0 " << i << endl;
		//y += delta;
		//delta -= 1;
	}
	return 0;
}