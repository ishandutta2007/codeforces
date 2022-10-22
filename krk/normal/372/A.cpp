#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 500005;

int n;
int a[Maxn];
int res;

bool Check(int x)
{
	for (int i = 0; i < x; i++)
		if (2 * a[i] > a[n - x + i]) return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int l = 0, r = n / 2;
	while (l <= r) {
		int m = l + r >> 1;
		if (Check(m)) { res = m; l = m + 1; }
		else r = m - 1;
	}
	printf("%d\n", n - res);
	return 0;
}