#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long double ld;

int n, l, v1, v2, k;

bool Possible(ld tim)
{
	int lft = n;
	ld passed = 0;
	ld pos = 0;
	while (lft > 0) {
		if (passed > tim) return false;
		ld y = ((tim - passed) * ld(v1) * v2 + pos * v1 - ld(l) * v1) / ld(v2 - v1);
		if (y < 0) return false;
		ld add = (l - y - pos) / ld(v2); passed += add;
		ld bus = pos + v2 * add;
		pos += v1 * add;
		add = (bus - pos) / ld(v2 + v1); passed += add;
		pos += v1 * add;
		lft -= k;
	}
	return true;
}

int main()
{
	scanf("%d %d %d %d %d", &n, &l, &v1, &v2, &k);
	ld lef = 0, rig = ld(l) / v1;
	for (int i = 0; i < 100; i++) {
		ld mid = (lef + rig) / 2;
		if (Possible(mid)) rig = mid;
		else lef = mid;
	}
	cout << fixed << setprecision(15) << rig << endl;
	return 0;
}