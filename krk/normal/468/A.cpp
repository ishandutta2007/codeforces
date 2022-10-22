#include <cstdio>
using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	if (n <= 3) printf("NO\n");
	else {
		printf("YES\n");
		while (n > 5) {
			printf("%d - %d = 1\n", n, n - 1);
			printf("1 * 1 = 1\n");
			n -= 2;
		}
		if (n == 5) {
			printf("4 * 5 = 20\n");
			printf("20 + 2 = 22\n");
			printf("22 + 3 = 25\n");
			printf("25 - 1 = 24\n");
		} else {
			printf("1 * 2 = 2\n");
			printf("2 * 3 = 6\n");
			printf("6 * 4 = 24\n");
		}
	}
	return 0;
}