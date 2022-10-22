#include <cstdio>
using namespace std;

int n;
int res;

int main()
{
	scanf("%d", &n);
	while (n--) {
		int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		res += (x2 - x1 + 1) * (y2 - y1 + 1);
	}
	printf("%d\n", res);
	return 0;
}