#include <cstdio>
using namespace std;

int n, k;

int main()
{
	scanf("%d %d", &n, &k);
	if (n == 1) {
		if (k == 0) printf("1\n");
		else printf("-1\n");
		return 0;
	}
	if (n / 2 > k) printf("-1\n");
	else {
		k = k - n / 2 + 1;
		int lst = 0;
		int i = 0;
		while (i + 2 + 2 <= n) {
			printf("%d %d ", lst + 1, lst + 2);
			lst += 2;
			i += 2;
		}
		int add = 0;
		while (add <= lst) add += k;
		printf("%d %d", add, add + k); lst = add + k; i += 2;
		if (i < n) printf(" %d", lst + 1);
		printf("\n");
	}
	return 0;
}