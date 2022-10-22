#include <cstdio>
using namespace std;

int n, k;

int main()
{
	scanf("%d %d", &n, &k);
	if (3 * k > n) printf("-1\n");
	else {
		for (int i = 0; i < 2 * k; i++)
			printf("%d ", i % k + 1);
		printf("%d ", k);
		n -= 2 * k + 1;
		for (int i = 0; i < n; i++)
			printf("%d%c", i % k + 1, i + 1 < n? ' ': '\n');
	}
	return 0;
}