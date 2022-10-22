#include <cstdio>
using namespace std;

int n, t;

int main()
{
	scanf("%d %d", &n, &t);
	int cur = 0;
	for (int i = 0; i < n - 1; i++) {
		printf("1"); cur = (10 * cur + 1) % t;
	}
	for (int i = (n == 1? 1: 0); i < 10; i++)
		if ((10 * cur + i) % t == 0) {
			printf("%d\n", i); return 0;
		}
    printf("-1\n");
	return 0;
}