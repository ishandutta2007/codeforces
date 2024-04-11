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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;


int main() {
	ll n;
	cin >> n;
	int fl = 0;
	for (ll i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			fl = 1;
			break;
		}
	}
	if (!fl) {
		cout << 1 << "\n";
		return 0;
	}
	if (n % 2 == 0) {
		cout << 2 << "\n";
		return 0;
	}
	fl = 0;
	for (ll i = 2; i * i <= n; ++i) {
		if ((n - 2) % i == 0) {
			fl = 1;
			break;
		}
	}
	if (!fl) {
		cout << 2 << "\n";
	}
	else {
		cout << 3 << "\n";
	}

	return 0;
}