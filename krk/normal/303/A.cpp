#include <cstdio>
using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	if (n % 2 == 0) printf("-1\n");
	else {
		for (int i = 0; i < n; i++)
			printf("%d%c", i, i + 1 < n? ' ': '\n');
		for (int i = 1; i <= n; i++)
			printf("%d%c", i % n, i + 1 <= n? ' ': '\n');
		for (int i = 0; i < n; i++)
			printf("%d%c", (1 + 2 * i) % n, i + 1 < n? ' ': '\n');
	}
	return 0;
}