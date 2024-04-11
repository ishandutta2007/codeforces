#include <cstdio>
#include <algorithm>
using namespace std;

int k, n, w;
int res;

int main()
{
	scanf("%d %d %d", &k, &n, &w);
	for (int i = 1; i <= w; i++)
		res += i * k;
	printf("%d\n", max(0, res - n));
	return 0;
}