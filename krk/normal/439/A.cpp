#include <cstdio>
using namespace std;

int n, d;
int sum;

int main()
{
	scanf("%d %d", &n, &d);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		sum += a;
	}
	if (sum + (n - 1) * 10 > d)
		printf("-1\n");
	else printf("%d\n", (d - sum) / 5);
	return 0;
}