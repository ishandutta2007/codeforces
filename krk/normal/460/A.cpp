#include <cstdio>
using namespace std;

int n, m;

int main()
{
	scanf("%d %d", &n, &m);
	int res = 1;
	while (n) {
		if (res == 0 || res % m) n--;
		res++;
	}
	printf("%d\n", res - 1);
	return 0;
}