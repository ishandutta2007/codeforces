#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 1005;

int n;
int X[Maxn], Y[Maxn];
ld res = 10e30l;

ld Dist(ld ax, ld ay) { return sqrt(ax * ax + ay * ay); }

ld Cross(ld ax, ld ay, ld bx, ld by) { return ax * by - ay * bx; }

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &X[i], &Y[i]);
	for (int i = 0; i < n; i++) {
		int ni = (i + 1) % n;
		res = min(res, Dist(X[ni] - X[i], Y[ni] - Y[i]) / 2.0l);
	}
	for (int i = 0; i < n; i++) {
		int ni = (i + 1) % n;
		int nni = (ni + 1) % n;
		ld ax = X[nni] - X[i], ay = Y[nni] - Y[i];
		ld bx = X[ni] - X[i], by = Y[ni] - Y[i];
		ld S = fabs(Cross(ax, ay, bx, by));
		ld d = S / Dist(ax, ay);
		res = min(res, d / 2.0l);
	}
	cout << fixed << setprecision(15) << res << endl;
	return 0;
}