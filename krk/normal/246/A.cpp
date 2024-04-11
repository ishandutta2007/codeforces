#include <cstdio>
using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	if (n <= 2) printf("-1\n");
	else for (int i = n; i >= 1; i--)
			printf("%d%c", i, i > 1? ' ': '\n');
	return 0;
}