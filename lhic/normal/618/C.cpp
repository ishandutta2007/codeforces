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

int n;

struct point {
	ll x, y;
	int n;
	ll operator*(point a) {
		return x * a.y - y * a.x;
	}
	point() {
	}
	point(ll X, ll Y) {
		x = X;
		y = Y;
	}
	point operator-(point a) {
		return point(x - a.x, y - a.y);
	}
};

point a[200000];


ll dst(point a, point b) {
	a = a - b;
	return a.x * a.x + a.y * a.y;
}

ll calc(point x) {
	return (a[1] - a[0]) * (x - a[0]);
}



int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld%lld", &a[i].x, &a[i].y), a[i].n = i;
	ll mn = dst(a[0], a[1]);
	int bst = 1;
	for (int i = 2; i < n; ++i) {
		ll cur = dst(a[0], a[i]);
		if (cur < mn)
			mn = cur, bst = i;
	}
	swap(a[1], a[bst]);
	mn = 9 * 1000000000ll * 1000000000ll;
	bst = 0;
	for (int i = 2; i < n; ++i) {
		ll cur = calc(a[i]);
		if (abs(cur) < mn && cur != 0)
			mn = abs(cur), bst = i;
	}
	swap(a[2], a[bst]);
	cout << a[0].n + 1 << " " << a[1].n + 1 << " " << a[2].n + 1 << "\n";
	return 0;
}