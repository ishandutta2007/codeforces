#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n, c;
int x[Maxn];
int res;

int main()
{
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	for (int i = 0; i + 1 < n; i++)
		res = max(res, x[i] - x[i + 1] - c);
	printf("%d\n", res);
	return 0;
}