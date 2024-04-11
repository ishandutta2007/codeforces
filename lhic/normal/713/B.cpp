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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

int n;

vector<int> vv[5];

int check(int x1, int y1, int x2, int y2) {
	if (x1 > x2 || y1 > y2)
		return 0;
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
	cout.flush();
	int a;
	cin >> a;
	return a;
}



int main() {
	cin >> n;
	int lb = 0;
	int rb = n;
	while (rb - lb > 1) {
		int mid = (rb + lb) / 2;
		if (check(1, 1, mid, n) >= 2)
			rb = mid;
		else
			lb = mid;
	}
	vv[0].push_back(rb);
	lb = 0;
	rb = n;
	while (rb - lb > 1) {
		int mid = (rb + lb) / 2;
		if (check(1, 1, mid, n) >= 1)
			rb = mid;
		else
			lb = mid;
	}
	vv[0].push_back(rb);

	lb = 0;
	rb = n;
	while (rb - lb > 1) {
		int mid = (rb + lb) / 2;
		if (check(1, 1, n, mid) >= 2)
			rb = mid;
		else
			lb = mid;
	}
	vv[1].push_back(rb);
	lb = 0;
	rb = n;
	while (rb - lb > 1) {
		int mid = (rb + lb) / 2;
		if (check(1, 1, n, mid) >= 1)
			rb = mid;
		else
			lb = mid;
	}
	vv[1].push_back(rb);

	lb = 0;
	rb = n + 1;
	while (rb - lb > 1) {
		int mid = (rb + lb) / 2;
		if (check(mid, 1, n, n) >= 2)
			lb = mid;
		else
			rb = mid;
	}
	vv[2].push_back(lb);
	lb = 0;
	rb = n + 1;
	while (rb - lb > 1) {
		int mid = (rb + lb) / 2;
		if (check(mid, 1, n, n) >= 1)
			lb = mid;
		else
			rb = mid;
	}
	vv[2].push_back(lb);

	lb = 0;
	rb = n + 1;
	while (rb - lb > 1) {
		int mid = (rb + lb) / 2;
		if (check(1, mid, n, n) >= 2)
			lb = mid;
		else
			rb = mid;
	}
	vv[3].push_back(lb);
	lb = 0;
	rb = n + 1;
	while (rb - lb > 1) {
		int mid = (rb + lb) / 2;
		if (check(1, mid, n, n) >= 1)
			lb = mid;
		else
			rb = mid;
	}
	vv[3].push_back(lb);

	for (int i1 = 0; i1 < 2; ++i1) {
		int ax2 = vv[0][i1];
		int bx2 = vv[0][1 - i1];
		for (int i2 = 0; i2 < 2; ++i2) {
			int ay2 = vv[1][i2];
			int by2 = vv[1][1 - i2];
			for (int i3 = 0; i3 < 2; ++i3) {
				int ax1 = vv[2][i3];
				int bx1 = vv[2][1 - i3];
				for (int i4 = 0; i4 < 2; ++i4) {
					int ay1 = vv[3][i4];
					int by1 = vv[3][1 - i4];
					if (max(ax1, bx1) > min(ax2, bx2) || max(ay1, by1) > min(ay2, by2)) {
						if (check(ax1, ay1, ax2, ay2) == 1 && check(bx1, by1, bx2, by2) == 1) {
							cout << "! " << ax1 << " " << ay1 << " " << ax2 << " " << ay2 << " " << bx1 << " " << by1 << " " << bx2 << " " << by2 << "\n";
							cout.flush();
							return 0;
						}
					}
				}
			}
		}
	}
	assert(false);

	return 0;
}