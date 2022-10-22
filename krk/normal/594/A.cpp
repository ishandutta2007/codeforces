#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 200005;
const int Inf = 2000000000;

int n;
int a[Maxn];
int res = Inf;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int tk = (n - 1) / 2;
	for (int i = 0; i <= tk; i++) {
		int lft = tk - i;
		res = min(res, a[n - 1 - lft] - a[i]);
	}
	printf("%d\n", res);
	return 0;
}