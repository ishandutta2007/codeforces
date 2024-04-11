#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 52;

int n, k;
int a[Maxn];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int i = n - k;
	if (i < 0 || i > 0 && a[i - 1] == a[i]) printf("-1\n");
	else printf("%d %d\n", a[i], a[i]);
	return 0;
}