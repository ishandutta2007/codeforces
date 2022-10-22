#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int res;

int main()
{
	scanf("%d %d", &n, &m);
	for (int a = 0; a <= n && 2 * a <= m; a++)
		res = max(res, a + min((n - a) / 2, m - 2 * a));
	printf("%d\n", res);
	return 0;
}