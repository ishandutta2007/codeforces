#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;

int Res(int x1, int y1, int x2, int y2)
{
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	int res; scanf("%d", &res);
	return res;
}

void Locate(int lvl, int &x1, int &y1, int &x2, int &y2)
{
	if (lvl == 4) return;
	if (lvl == 0) {
		int l = x1, r = x2;
		while (l <= r) {
			int m = l + r >> 1;
			if (Res(m, y1, x2, y2) == 1) { x1 = m; l = m + 1; }
			else r = m - 1;
		}
	} else if (lvl == 1) {
		int l = y1, r = y2;
		while (l <= r) {
			int m = l + r >> 1;
			if (Res(x1, m, x2, y2) == 1) { y1 = m; l = m + 1; }
			else r = m - 1;
		}
	} else if (lvl == 2) {
		int l = x1, r = x2;
		while (l <= r) {
			int m = l + r >> 1;
			if (Res(x1, y1, m, y2) == 1) { x2 = m; r = m - 1; }
			else l = m + 1;
		}
	} else if (lvl == 3) {
		int l = y1, r = y2;
		while (l <= r) {
			int m = l + r >> 1;
			if (Res(x1, y1, x2, m) == 1) { y2 = m; r = m - 1; }
			else l = m + 1;
		}
	}
	Locate(lvl + 1, x1, y1, x2, y2);
}

bool byX()
{
	int l = 1, r = n;
	int res1 = -1;
	while (l <= r) {
		int m = l + r >> 1;
		int g = Res(1, 1, m, n);
		if (g == 0) l = m + 1;
		else if (g == 1) { res1 = m; r = m - 1; }
		else r = m - 1;
	}
	if (res1 == -1) return false;
	l = res1 + 1, r = n;
	int res2 = -1;
	while (l <= r) {
		int m = l + r >> 1;
		int g = Res(m, 1, n, n);
		if (g == 0) r = m - 1;
		else if (g == 1) { res2 = m; l = m + 1; }
		else l = m + 1;
	}
	if (res2 == -1) return false;
	if (res1 >= res2) return false;
	int x1 = 1, y1 = 1, x2 = res1, y2 = n; Locate(0, x1, y1, x2, y2);
	int x3 = res2, y3 = 1, x4 = n, y4 = n; Locate(0, x3, y3, x4, y4);
	printf("! %d %d %d %d %d %d %d %d\n", x1, y1, x2, y2, x3, y3, x4, y4);
	fflush(stdout);
	return true;
}

bool byY()
{
	int l = 1, r = n;
	int res1 = -1;
	while (l <= r) {
		int m = l + r >> 1;
		int g = Res(1, 1, n, m);
		if (g == 0) l = m + 1;
		else if (g == 1) { res1 = m; r = m - 1; }
		else r = m - 1;
	}
	if (res1 == -1) return false;
	l = res1 + 1, r = n;
	int res2 = -1;
	while (l <= r) {
		int m = l + r >> 1;
		int g = Res(1, m, n, n);
		if (g == 0) r = m - 1;
		else if (g == 1) { res2 = m; l = m + 1; }
		else l = m + 1;
	}
	if (res2 == -1) return false;
	if (res1 >= res2) return false;
	int x1 = 1, y1 = 1, x2 = n, y2 = res1; Locate(0, x1, y1, x2, y2);
	int x3 = 1, y3 = res2, x4 = n, y4 = n; Locate(0, x3, y3, x4, y4);
	printf("! %d %d %d %d %d %d %d %d\n", x1, y1, x2, y2, x3, y3, x4, y4);
	fflush(stdout);
	return true;
}

int main()
{
	scanf("%d", &n);
	if (!byX())
		byY();
	return 0;
}