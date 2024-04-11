#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n;
int a[Maxn];

int Get(int n)
{
	if (n == 3) return max(max(a[0], a[1]), a[2]);
	int tk = max(a[n - 2], a[n - 1]);
	a[(n - 1) / 2 - 1] = max(a[(n - 1) / 2 - 1] - tk, 0);
	return Get(n - 2) + tk;
}

int main()
{
	scanf("%d", &n);
	if (n == 1 || n % 2 == 0) { printf("-1\n"); return 0; }
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d\n", Get(n));
	return 0;
}