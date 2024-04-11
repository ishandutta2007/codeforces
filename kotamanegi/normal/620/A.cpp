#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <algorithm>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream> 
#include<map>
#include <list>
using namespace std;
#define REP(a,b) for(int a = 0;a < b;++a)
int zettai(int a, int b) {
	if (a > b) {
		return a - b;
	}
	else {
		return b - a;
	}
}
int main() {
	int x1, x2, y1, y2;
	int d = 0;
	cin >> x1 >> y1 >> x2 >> y2;
	while (true) {
		if (x1 == x2 || y1 == y2) {
			if (x1 == x2 && y1 == y2) {
				printf("%d", d);
				return 0;
			}
			else if (x1 == x2) {
				d += zettai(y1, y2);
				printf("%d", d);
				return 0;
			}
			else {
				d += zettai(x1, x2);
				printf("%d", d);
				return 0;
			}
		}
		else {
			int hoge_x = zettai(x1, x2);
			int hoge_y = zettai(y1, y2);
			if (hoge_x > hoge_y) {
				d = hoge_y;
			}
			else {
				d = hoge_x;
			}
			if (x1 < x2) {
				x1 += d;
				if (y1 < y2) {
					y1 += d;
				}
				else {
					y1 -= d;
				}
			}
			else {
				x1 -= d;
				if (y1 < y2) {
					y1 += d;
				}
				else {
					y1 -= d;
				}
			}
		}
	}
}