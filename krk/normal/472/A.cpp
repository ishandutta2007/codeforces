#include <cstdio>
using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	if (n % 2) printf("%d %d\n", 9, n - 9);
	else printf("%d %d\n", 4, n - 4);
	return 0;
}