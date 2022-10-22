#include <cstdio>
using namespace std;

int n, k;

int main()
{
	scanf("%d %d", &n, &k);
	if (n * (n - 1) / 2 <= k) printf("no solution\n");
	else {
		int pr = 1000000000;
		for (int i = 0; i < n; i++)
			if (i % 2 == 0) printf("%d %d\n", i, pr);
			else {
				printf("%d %d\n", i, -pr);
				pr -= n;
			}
	}
	return 0;
}