#include <cstdio>
#include <algorithm>
using namespace std;

int n, x;
int st;
int res;

int main()
{
	scanf("%d %d", &n, &x);
	while (n--) {
		int a; scanf("%d", &a);
		st += a;
	}
	st = abs(st);
	for (int i = x; i > 0; i--)
		while (i <= st) { st -= i; res++; }
	printf("%d\n", res);
	return 0;
}