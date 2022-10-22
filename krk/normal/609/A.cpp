#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n, m;
int a[Maxn];
int res;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int i = n - 1;
	while (res < m) {
		res += a[i];
		i--;
	}
	printf("%d\n", n - 1 - i);
	return 0;
}