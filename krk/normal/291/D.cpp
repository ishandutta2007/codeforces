#include <cstdio>
using namespace std;

int n, k;
int p;

int main()
{
	scanf("%d %d", &n, &k);
	p = n - 1;
	while (k--) {
		for (int i = 1; i <= n; i++)
			printf("%d%c", i < p? n - p + i: n, i + 1 <= n? ' ': '\n');
		if (p >= 1) p = 2 * p - n;
	}
	return 0;
}