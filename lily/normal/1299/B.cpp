#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second
#define N int(1e5 + 7)

int n;
struct Point {
	long long x, y;
	Point operator - (const Point &a) const {
		return {x - a.x, y - a.y};
	}
	Point operator + (const Point &a) const {
		return {x + a.x, y + a.y};
	}
	bool operator == (const Point &a) const {
		return x == a.x && y == a.y;
	}
} a[N];

int main() {
	read(n);
	if (n & 1) {
		printf("No\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		int x, y;
		read(x); read(y);
		a[i].x = x, a[i].y = y;
	}
	Point cen = a[0] + a[n / 2];
	for (int i = 0; i < n; i++) {
		int j = (i + n / 2) % n;
		if (a[i] + a[j] == cen);
		else {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}