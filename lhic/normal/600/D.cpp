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

const ld PI = acos((ld)-1);

ld d;
ll dd;

ld get(ll r1, ll r2) {
	ld ang = acos((r1 * r1 - r2 * r2 + dd) / ((ld)2.0 * r1 * d));
	return r1 * r1 * ang - r1 * r1 * sin(2 * ang) / 2;
}


int main() {

	ll x1, x2, y1, y2;
	ll r1, r2;
	cin >> x1 >> y1 >> r1;
	cin >> x2 >> y2 >> r2;
	dd = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	d = sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if ((r1 + r2) * (r1 + r2) <= dd) {
		cout << 0 << "\n";
		return 0;
	}
	cout.setf(ios::fixed);
	cout.precision(20);
	if (r1 < r2)
		swap(r1, r2);
	if (dd <= (r1 - r2) * (r1 - r2)) {
		cout << (PI * r2) * r2 << "\n";
		return 0;
	}


	ld ans = get(r1, r2);
	ans += get(r2, r1);
	cout << ans << "\n";

	return 0;
}