#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n, k;
int a[Maxn];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	printf("%d\n", a[n - k]);
	return 0;
}