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


int main() {
	int h1, h2;
	int a, b;
	cin >> h1 >> h2;
	cin >> a >> b;
	h1 -= a * 4;
	ll h = h2 - h1;
	for (int i = 0; i < 300000; ++i) {
		h -= a * 12;
		if (h <= 0) {
			cout << i << "\n";
			return 0;
		}
		h += b * 12;
	}
	cout << -1 << "\n";
	return 0;
}