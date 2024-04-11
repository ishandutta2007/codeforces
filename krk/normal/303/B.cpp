#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, m, x, y, a, b;

int gcd(int x, int y) { return x == 0? y: gcd(y % x, x); }

void Fix(int &x1, int &y1, int &x2, int &y2)
{
	if (x1 < 0) { x2 -= x1; x1 = 0; }
	if (x2 > n) { x1 -= x2 - n; x2 = n; }
	if (y1 < 0) { y2 -= y1; y1 = 0; }
	if (y2 > m) { y1 -= y2 - m; y2 = m; }
}

int main()
{
	scanf("%d %d %d %d %d %d", &n, &m, &x, &y, &a, &b);
	int g = gcd(a, b); a /= g; b /= g;
	int mn = min(n / a, m / b); a *= mn; b *= mn;
	int x1 = x - (a + 1) / 2, y1 = y - (b + 1) / 2;
	int x2 = x1 + a, y2 = y1 + b;
	Fix(x1, y1, x2, y2);
	printf("%d %d %d %d\n", x1, y1, x2, y2);
	return 0;
}