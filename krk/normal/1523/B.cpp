#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
		}
		printf("%d\n", n * 3);
		for (int i = 0; i + 1 < n; i += 2) {
			int a = i + 1, b = i + 2;
			printf("2 %d %d\n", a, b);
			printf("1 %d %d\n", a, b);
			printf("1 %d %d\n", a, b);
			printf("2 %d %d\n", a, b);
			printf("1 %d %d\n", a, b);
			printf("1 %d %d\n", a, b);
		}
	}
    return 0;
}