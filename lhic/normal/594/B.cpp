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


int main() {
	ios_base::sync_with_stdio(false);
	cout.setf(ios::fixed);
	cout.precision(8);
	int n;
	ld r, v;
	cin >> n >> r >> v;
	v /= r;
	for (int i = 0; i < n; ++i) {
		ld s, f;
		ld l;
		cin >> s >> f;
		l = f - s;
		l /= r;
		ld tl = 0;
		ld tr = (l + 10) / v;
		for (int it = 0; it < 50; ++it) {
			ld t = (tl + tr) / 2;
			ld al = atan2(cos(v * t) - 1, sin(v * t));
			if (v * t + sin(al) - sin(al + v * t) >= l || v * t - sin(al) + sin(al + v * t) >= l)
				tr = t;
			else
				tl = t;
		}
		cout << tr<< "\n";
	}
	return 0;
}