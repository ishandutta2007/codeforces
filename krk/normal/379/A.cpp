#include <cstdio>
using namespace std;

int a, b;
int res;

int main()
{
	scanf("%d %d", &a, &b);
	while (a >= b) {
		res += a / b * b;
		a = a / b + a % b;
	}
	res += a;
	printf("%d\n", res);
	return 0;
}