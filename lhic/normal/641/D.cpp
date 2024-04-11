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

const int MAXN = 120000;

ld mx[MAXN];
ld mn[MAXN];
int n;
ld a[MAXN];
ld b[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		double x;
		scanf("%lf", &x);
		mx[i] = x;
	}
	for (int i = 0; i < n; ++i) {
		double x;
		scanf("%lf", &x);
		mn[i] = x;
	}
	for (int i = 0; i < n; ++i)
		mx[i + 1] += mx[i];
	mn[n] = 0;
	for (int i = n - 1; i >= 0; --i)
		mn[i] += mn[i + 1];
	for (int i = 0; i < n; ++i) {
		ld sm = 1.0 - mn[i + 1] + mx[i];
		ld pr = mx[i];
		ld sq = sm * sm - 4 * pr;
		if (sq < 0)
			sq = 0;
		else
			sq = sqrt(sq);
		a[i] = (sm - sq) / 2;
		b[i] = (sm + sq) / 2;
	}
	for (int i = n - 1; i > 0; --i)
		a[i] = a[i] - a[i - 1];
	for (int i = n - 1; i > 0; --i)
		b[i] = b[i] - b[i - 1];
	for (int i = 0; i < n; ++i) {
		if (a[i] < 0) {
			assert(a[i] > -1e-6);
			a[i] = 0;
		}
		if (b[i] < 0) {
			assert(b[i] > -1e-6);
			b[i] = 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%.7f ", (double)a[i]);
	}
	printf("\n");
	for (int i = 0; i < n; ++i) {
		printf("%.7f ", (double)b[i]);
	}

	return 0;
}