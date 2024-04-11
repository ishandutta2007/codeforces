#include <iostream>
#include <cstdio>

using namespace std;

int a, b, c, d, x, y, x1, y1, x2, y2;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &x, &y, &x1, &y1, &x2, &y2);
		x += b - a;
		y += d - c;
		if ((x == x1 && x == x2 && (a || b)) || (y == y1 && y == y2 && (c || d))) puts("NO");
		else puts((x1 <= x && x <= x2 && y1 <= y && y <= y2) ? "YES" : "NO"); 
	}
	return 0;
}