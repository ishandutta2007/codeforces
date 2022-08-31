#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

ll a00, a01, a10, a11;

void imp() {
	cout << "Impossible\n";
	exit(0);
}

int main() {
	cin >> a00 >> a01 >> a10 >> a11;
	if (a00 == 0 && a01 == 0 && a10 == 0 && a11 == 0) {
		cout << "0\n";
		return 0;
	}
	ll c0 = 0;
	ll c1 = 0;
	if (a01 || a10)
		c1 = 1, c0 = 1;
	while (c0 * (c0 - 1) / 2 < a00)
		++c0;
	while (c1 * (c1 - 1) / 2 < a11)
		++c1;
	if (c0 * (c0 - 1) / 2 != a00) {
		imp();
	}
	if (c1 * (c1 - 1) / 2 != a11) {
		imp();
	}
	ll cnt = c0 * c1;
	if (cnt != a01 + a10)
		imp();

	int n = c0 + c1;
	if (n == 0)
		imp();
	for (int i = 0; i < n; ++i) {
		if (a01 >= c1) {
			printf("0");
			a01 -= c1;
			--c0;
		}
		else {
			a10 -= c0;
			printf("1");
			--c1;
		}
	}
	printf("\n");

	return 0;
}