#include <cstdio>
#include <cmath>
using namespace std;

typedef long double ld;

int n, m;

ld Case1() { return 2 * sqrt(ld(n) * n + m * m) + n; }

ld Case2() { return sqrt(ld(n) * n + m * m) + 2 * sqrt(ld(n) * n + (m - 1) * (m - 1)); }

ld Case3() { return 2 * sqrt(ld(n) * n + m * m) + m; }

ld Case4() { return sqrt(ld(n) * n + m * m) + 2 * sqrt(ld(n - 1) * (n - 1) + m * m); }

int main()
{
	scanf("%d %d", &n, &m);
	if (n == 0) {
		printf("0 %d\n", m - 1);
		printf("0 0\n");
		printf("0 %d\n", m);
		printf("0 1\n");
	} else if (m == 0) {
		printf("%d 0\n", n - 1);
		printf("0 0\n");
		printf("%d 0\n", n);
		printf("1 0\n");
	} else if (n >= m)
		if (Case1() >= Case2()) {
			printf("%d %d\n", n, m);
			printf("0 0\n");
			printf("%d %d\n", n, 0);
			printf("%d %d\n", 0, m);
		} else {
			printf("%d %d\n", n, m - 1);
			printf("0 0\n");
			printf("%d %d\n", n, m);
			printf("0 1\n");
		}
	else if (Case3() >= Case4()) {
			printf("%d %d\n", n, m);
			printf("0 0\n");
			printf("%d %d\n", 0, m);
			printf("%d %d\n", n, 0);
		} else {
			printf("%d %d\n", n - 1, m);
			printf("0 0\n");
			printf("%d %d\n", n, m);
			printf("1 0\n");
		}
	return 0;
}