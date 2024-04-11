#include <cstdio>
#include <algorithm>
using namespace std;

int n, s;
int best = -1;

int main()
{
	scanf("%d %d", &n, &s);
	while (n--) {
		int x, y; scanf("%d %d", &x, &y);
		if (100 * s >= 100 * x + y)
			best = max(best, (100 - y) % 100);
	}
	printf("%d\n", best);
	return 0;
}