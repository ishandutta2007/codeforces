/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
typedef long double LD;
#define eps 1e-12

int n;
int X1, Y1, X2, Y2;


int main() {
	cin >> n;
	cin >> X1 >> Y1 >> X2 >> Y2;
	LD l = 0, r = 1e18;
	for (int i = 1; i <= n; i++) {
		int rx, ry, vx, vy;
		cin >> rx >> ry >> vx >> vy;
		if (vx == 0) {
			if (rx - eps < X1 || rx + eps > X2) return puts("-1"), 0;
		}
		else {
			LD a = LD(X1 - rx) / vx, b = LD(X2 - rx) / vx;
			if (a > b) swap(a, b);
			l = max(l, a);
			r = min(r, b);
		}
		if (vy == 0) {
			if (ry - eps < Y1 || ry + eps > Y2) return puts("-1"), 0;
		}
		else {
			LD a = LD(Y1 - ry) / vy, b = LD(Y2 - ry) / vy;
			if (a > b) swap(a, b);
			l = max(l, a);
			r = min(r, b);
		}
	}
	if (l < r - eps) printf("%.12lf\n", (double)l);
	else puts("-1");
	return 0;
}