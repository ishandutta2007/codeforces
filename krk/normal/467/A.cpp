#include <cstdio>
using namespace std;

int n;
int p, q;
int res;

int main()
{
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &p, &q);
		if (p + 2 <= q) res++;
	}
	printf("%d\n", res);
	return 0;
}