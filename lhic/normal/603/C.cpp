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
int n, k;

ll getG(int x) {
	if (x == 1)
		return 1;
	if (x == 0)
		return 0;
	if (x % 2 == 1) {
		ll kk = getG(x - 1);
		if (kk == 0)
			return 1;
		else
			return 0;
	}
	if (k == 0) {
		if (x == 2)
			return 2;
		return 1;
	}
	else {
		if (x == 2)
			return 0;
		else if (x == 3)
			return 1;
		else if (x == 4)
			return 2;
		if (getG(x / 2) == 1)
			return 2;
		else
			return 1;
	}
}

int a[120000];

int main() {
	scanf("%d%d", &n, &k);
	k %= 2;
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	ll ans = 0;
	for (int i = 0; i < n; ++i)
		ans ^= getG(a[i]);
	if (ans == 0)
		cout << "Nicky\n";
	else
		cout << "Kevin\n";
	return 0;
}