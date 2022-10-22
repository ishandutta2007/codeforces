#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <math.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

ll sqr(int x) {
	return 1ll * x * x;
}

bool solve() {

	cout.precision(10);
	cout << fixed;

	int n, x, y;

	cin >> n >> x >> y;

	ld mx = -inf64, mn = inf64;

	vec< pii > a(n);

	for(int i = 0;i < n;i++) {
		int tx, ty;
		scanf("%d %d", &tx, &ty);
		mx = max(mx, (ld)sqr(tx - x) + (ld)sqr(ty - y));
		mn = min(mn, (ld)sqr(tx - x) + (ld)sqr(ty - y));
		a[i] = mp(tx, ty);
	}

	for(int i = 0;i < n;i++) {
		int x1, y1, x2, y2;
		tie(x1, y1) = a[i];
		tie(x2, y2) = a[(i + 1) % n];
		ld A, B, C;

		A = y2 - y1;
		B = x1 - x2;
		C = 1ll * x1 * (y1 - y2) + 1ll * y1 * (x2 - x1);

		ld u;

		u = ((A * x + B * y + C) / (A * A + B * B)) * (A * x + B * y + C);

		ld D = sqr(x1 - x2) + sqr(y1 - y2);
		ld t1 = sqr(x - x1) + sqr(y - y1);
		ld t2 = sqr(x - x2) + sqr(y - y2);

		if(D + t1 > t2 && D + t2 > t1) {
			mn = min(mn, u);
		}
	}

	cout << pi * (mx - mn) << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}