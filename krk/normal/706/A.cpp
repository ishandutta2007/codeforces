#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long double ld;

ld Dist(ld ax, ld ay) { return sqrt(ax * ax + ay * ay); }

int a, b;
int n;
int x, y, v;
ld res = 1e30;

int main()
{
	scanf("%d %d", &a, &b);
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d %d", &x, &y, &v);
		res = min(res, Dist(x - a, y - b) / v);
	}
	cout << fixed << setprecision(15) << res << endl;
	return 0;
}