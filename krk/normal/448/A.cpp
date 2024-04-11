#include <cstdio>
using namespace std;

int a1, a2, a3;
int b1, b2, b3;
int a, b;
int n;

int main()
{
	scanf("%d %d %d", &a1, &a2, &a3);
	a = a1 + a2 + a3;
	scanf("%d %d %d", &b1, &b2, &b3);
	b = b1 + b2 + b3;
	scanf("%d", &n);
	int need = a / 5 + (a % 5 > 0) + b / 10 + (b % 10 > 0);
	printf("%s\n", need <= n? "YES": "NO");
	return 0;
}