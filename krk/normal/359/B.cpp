#include <cstdio>
using namespace std;

int n, k;

int main()
{
	scanf("%d %d", &n, &k);
	int cur = 1;
	for (int i = 0; i < k; i++) {
		printf("%d %d%c", 2 * cur, 2 * cur - 1, cur < n? ' ': '\n');
		cur++;
	}
	while (cur <= n) {
		printf("%d %d%c", 2 * cur - 1, 2 * cur, cur < n? ' ': '\n');
		cur++;
	}
	return 0;
}