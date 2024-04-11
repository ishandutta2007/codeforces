#include <bits/stdc++.h>
using namespace std;

int x1, y1, x2, y2;
int x3, y3, x4, y4;

int main() {
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	if (x1 == x2) {
		if (y1 > y2) swap(y1, y2);
		y3 = y1;
		y4 = y2;
		x3 = x1 + (y2 - y1);
		x4 = x3;
	} else if (y1 == y2) {
		if (x1 > x2) swap(x1, x2);
		x3 = x1;
		x4 = x2;
		y3 = y1 + (x2 - x1);
		y4 = y3;
	} else {
		if (abs(x1 - x2) != abs(y1 - y2)) {
			printf("-1\n");
			return 0;
		}
		x3 = x1;
		y3 = y2;
		x4 = x2;
		y4 = y1;
	}
	printf("%d %d %d %d\n", x3, y3, x4, y4);
	return 0;
}