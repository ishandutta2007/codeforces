#include <cstdio>
using namespace std;

typedef long long ll;

int n;

int main()
{
	scanf("%d", &n);
	if (n % 2) { printf("0\n"); return 0; }
	n /= 2;
	int ways = (n - 1) / 2;
	printf("%d\n", ways);
	return 0;
}