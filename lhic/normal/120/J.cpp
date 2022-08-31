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

struct point {
	int x, y, n, t;
};

bool cmp(point a, point b) {
	return a.x < b.x;
}
bool cmp2(point a, point b) {
	return a.y < b.y;
}


vector<point> vv;
int n;
int bstd;
int bsti, bstj, bstk1, bstk2;

void run(int l, int r) {
	if (l + 1 == r)
		return;
	int m = (l + r) / 2;
	int xm = vv[m].x;
	run(l, m);
	run(m, r);
	inplace_merge(vv.begin() + l, vv.begin() + m, vv.begin() + r, cmp2);
	vector<point> aa;
	for (int i = l; i < r; ++i)
		if ((xm - vv[i].x) * (xm - vv[i].x) < bstd)
			aa.push_back(vv[i]);
	for (int i = 0; i < (int)aa.size(); ++i) {
		for (int j = i + 1; j < (int)aa.size() && (aa[j].y - aa[i].y) * (aa[j].y - aa[i].y) < bstd; ++j)
			if (aa[i].n != aa[j].n) {
				if ((aa[i].x - aa[j].x) * (aa[i].x - aa[j].x) + (aa[i].y - aa[j].y) * (aa[i].y - aa[j].y) < bstd) {
					bstd = (aa[i].x - aa[j].x) * (aa[i].x - aa[j].x) + (aa[i].y - aa[j].y) * (aa[i].y - aa[j].y);
					bsti = aa[i].n;
					bstk1 = aa[i].t;
					bstj = aa[j].n;
					bstk2 = aa[j].t;
				}
			}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		point a;
		a.n = i;
		
		a.x = x;
		a.y = y;
		a.t = 1;
		vv.push_back(a);
		a.x = -x;
		a.y = y;
		a.t = 2;
		vv.push_back(a);
		a.x = x;
		a.y = -y;
		a.t = 3;
		vv.push_back(a);
		a.x = -x;
		a.y = -y;
		a.t = 4;
		vv.push_back(a);
	}
	sort(vv.begin(), vv.end(), cmp);
	bstd = 1e9;
	bsti = 0;
	bstj = 0;
	bstk1 = 0;
	bstk2 = 0;

	run(0, vv.size());
	printf("%d %d %d %d", bsti + 1, bstk1, bstj + 1, 5 - bstk2);
	return 0;
}