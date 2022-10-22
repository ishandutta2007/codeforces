#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;

int main()
{
	scanf("%d %d", &n, &m);
	int res = min(n, m) + 1;
	printf("%d\n", res);
	for (int i = 0; i < res; i++)
		printf("%d %d\n", n - i, i);
	return 0;
}