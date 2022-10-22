#include <cstdio>
using namespace std;

int n;
int sum1, sum2;
bool was;

int main()
{
	scanf("%d", &n);
	while (n--) {
		int a, b; scanf("%d %d", &a, &b);
		if (a % 2 != b % 2) was = true;
		sum1 += a; sum2 += b;
	}
	if (sum1 % 2 != sum2 % 2) printf("-1\n");
	else if (sum1 % 2 == 0) printf("0\n");
	else if (was) printf("1\n");
	else printf("-1\n");
	return 0;
}