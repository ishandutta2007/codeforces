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

int n;

struct st {
	ld x, y;
	ld ang;
};

st merge(const st& a, const st& b) {
	st ans;
	ans.ang = a.ang + b.ang;
	ans.x = a.x + b.x * cos(a.ang) - b.y * sin(a.ang);
	ans.y = a.y + b.x * sin(a.ang) + b.y * cos(a.ang);
	return ans;
}

const int MAXN = 310000;

st rmq[MAXN * 4];
st arr[MAXN];


void build(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		rmq[v] = arr[tl];
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	rmq[v] = merge(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

void upd(int v, int tl, int tr, int x) {
	if (tl + 1 == tr) {
		rmq[v] = arr[tl];
		return;
	}
	int m = (tl + tr) >> 1;
	if (x < m)
		upd(v * 2 + 1, tl, m, x);
	else
		upd(v * 2 + 2, m, tr, x);
	rmq[v] = merge(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

const ld PI = acos(-1.0);


int main() {
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		arr[i].x = 1, arr[i].y = 0, arr[i].ang = 0;
	build(0, 0, n);
	for (int i = 0; i < m; ++i) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		--y;
		if (x == 1) {
			arr[y].x += z * cos(arr[y].ang);
			arr[y].y += z * sin(arr[y].ang);
		}
		else {
			ld z2 = -z;
			z2 = z2 * PI / 180.0;
			st xx;
			xx.x = 0;
			xx.y = 0;
			xx.ang = z2;
			arr[y] = merge(xx, arr[y]);
		}
		upd(0, 0, n, y);
		st ans = rmq[0];
		printf("%.9lf %.9lf\n", (double)ans.x, (double)ans.y);
	}
	return 0;
}