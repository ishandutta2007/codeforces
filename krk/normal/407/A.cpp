#include <cstdio>
#include <algorithm>
using namespace std;

int a, b;

int main()
{
	scanf("%d %d", &a, &b);
	int p1 = a, p2;
	for (int i = 1; i < a; i++) {
		while (i * i + p1 * p1 > a * a) p1--;
		if (i * i + p1 * p1 == a * a) {
			int p2 = b;
			for (int j = 1; j < b; j++) {
				while (j * j + p2 * p2 > b * b) p2--;
				if (j * j + p2 * p2 == b * b && (i + j) * (i + j) + abs(p1 - p2) * abs(p1 - p2) == a * a + b * b && abs(p1 - p2)) {
					printf("YES\n");
					printf("%d %d\n", p1, i);
					printf("%d %d\n", p2, -j);
					printf("0 0\n");
					return 0;
				}
			}
		}
	}
	printf("NO\n");
	return 0;
}