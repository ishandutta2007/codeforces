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

const ld PI = acos(-1.0);
ll x[200000];
ll y[200000];

ld gg(int i, ld k) {
	ld xx = x[i] + k * (x[i + 1] - x[i]);
	ld yy = y[i] + k * (y[i + 1] - y[i]);
	return sqrt(xx *xx + yy * yy);
}

int main() {
	int n;
	ll x0, y0;
	scanf("%d", &n);
	scanf("%lld%lld", &x0, &y0);
	ld mn = 0, mx = 0;
	for (int i = 0; i < n; ++i)
		scanf("%lld%lld", x + i, y + i), x[i] -= x0, y[i] -= y0;
	for (int i = 0; i < n; ++i) {
		ld d = x[i] * x[i] + y[i] * y[i];
		d = sqrt(d);
		if (i == 0)
			mn = mx = d;
		else
			mn = min(mn, d), mx = max(mx, d);
	}
	x[n] = x[0];
	y[n] = y[0];
	for (int i = 0; i < n; ++i) {
		ld l = 0;
		ld r = 1;
		for (int it = 0; it < 60; ++it) {
			ld m1 = l + 4 * (r - l) / 9;
			ld m2 = m1 + (r - l) / 9;
			ld d1 = gg(i, m1);
			ld d2 = gg(i, m2);
			if (d1 < d2)
				r = m2;
			else
				l = m1;
		}
		mn = min(mn, gg(i, (l + r) / 2));
	}
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << PI * (mx * mx - mn * mn) << "\n";
	return 0;
}