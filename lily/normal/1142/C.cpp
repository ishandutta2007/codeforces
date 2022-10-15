#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define x first
#define y second
#define mp(a, b) make_pair(a, b)
#define read(a) scanf("%d", &a)

#define N 1000005

struct Point {
	LL x, y;
	bool operator < (const Point &a) const {
		return x < a.x || (x == a.x && y > a.y);
	}
	Point operator - (const Point &a) const {
		return {x - a.x, y - a.y};
	}
	LL operator * (const Point &a) const {
		return x * a.y - y * a.x;
	}
} a[N], b[N];
int n;

Point s[N];


bool ok(Point a, Point b, Point c) {
	LD B = (b.y - b.x * b.x - a.y + a.x * a.x) / LD(b.x - a.x);
	LD C = a.y - (a.x * a.x + B * a.x);
	LD yy = c.x * c.x + c.x * B + C;
	return yy > c.y;
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &a[i].x, &a[i].y);
	}
	sort(a + 1, a + n + 1);
	b[0].x = a[1].x - 1;
	int j = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i].x != b[j].x) b[++j] = a[i];
	}
	n = j;
	b[0] = b[n + 1] = {0, -1234567890}; 
	int top = 0;
	for (int i = 1; i <= n; i++) {
		while (top > 1 && !ok(s[top - 1], s[top], b[i])) top--;
		s[++top] = b[i];
	}
	printf("%d\n", top - 1);
	return 0;
}