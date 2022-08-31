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
typedef double ld;

using namespace std;

ll a, b, c, d;

int main() {
	cin >> a >> b;
	cin >> c >> d;
	ld l = 0;
	ld r = max(max(abs(a), abs(b)), max(abs(c), abs(d)));
	for (int it = 0; it < 100; ++it) {
		ld x = (l + r) / 2;
		ld mn1 = min(min((a - x) * (d - x), (a - x) * (d + x)), min((a + x) * (d - x), (a + x) * (d + x)));
		ld mx1 = max(max((a - x) * (d - x), (a - x) * (d + x)), max((a + x) * (d - x), (a + x) * (d + x)));
		swap(a, c);
		swap(b, d);
		ld mn2 = min(min((a - x) * (d - x), (a - x) * (d + x)), min((a + x) * (d - x), (a + x) * (d + x)));
		ld mx2 = max(max((a - x) * (d - x), (a - x) * (d + x)), max((a + x) * (d - x), (a + x) * (d + x)));
		swap(a, c);
		swap(b, d);
		if (mx1 < mn2 || mx2 < mn1)
			l = x;
		else
			r = x;
	}
	cout.setf(ios::fixed);
	cout.precision(10);
	cout << r;
	return 0;
}