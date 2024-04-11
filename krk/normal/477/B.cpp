#include <cstdio>
using namespace std;

int n, k;

int main()
{
	scanf("%d %d", &n, &k);
	printf("%d\n", k * (6 * n - 1));
	int nxt = 1;
	for (int i = 0; i < n; i++) {
		printf("%d ", k * nxt); nxt++;
		printf("%d ", k * nxt); nxt++;
		printf("%d ", k * nxt); nxt += 2;
		printf("%d\n", k * nxt); nxt += 2;
	}
	return 0;
}