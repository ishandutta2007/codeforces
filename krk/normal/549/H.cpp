#include <cstdio>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long double ld;

const ld Inf = 1e30;

int a, b, c, d;

bool Ok(ld x)
{
	ld mn = Inf, mx = -Inf;
	for (int ia = -1; ia <= 1; ia += 2)
		for (int ib = -1; ib <= 1; ib += 2)
			for (int ic = -1; ic <= 1; ic += 2)
				for (int id = -1; id <= 1; id += 2) {
					ld ca = a + ia * x;
					ld cb = b + ib * x;
					ld cc = c + ic * x;
					ld cd = d + id * x;
					ld val = ca * cd - cb * cc;
					mn = min(mn, val); mx = max(mx, val);
				}
	return mn <= 0 && 0 <= mx;
}

int main()
{
	scanf("%d %d %d %d", &a, &b, &c, &d);
	ld lef = 0.0, rig = 1000000000.0l;
	for (int i = 0; i < 100; i++) {
		ld mid = (lef + rig) / 2;
		if (Ok(mid)) rig = mid;
		else lef = mid;
	}
	cout << fixed << setprecision(10) << rig << endl;
	return 0;
}