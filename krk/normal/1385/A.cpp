#include <bits/stdc++.h>
using namespace std;

int T;
int x, y, z;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &x, &y, &z);
		if (x == y && x == z) {
			printf("YES\n");
			printf("%d %d %d\n", x, y, z);
			continue;
		}
		if (x == y)
			if (x > z) {
				printf("YES\n");
				printf("%d %d %d\n", x, z, z);
			} else printf("NO\n");
		else if (x == z)
			if (x > y) {
				printf("YES\n");
				printf("%d %d %d\n", y, x, y);
			} else printf("NO\n");
		else if (y == z)
			if (y > x) {
				printf("YES\n");
				printf("%d %d %d\n", x, x, y);
			} else printf("NO\n");
		else printf("NO\n");
	}
    return 0;
}