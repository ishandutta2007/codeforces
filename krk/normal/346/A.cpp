#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n;
int a[Maxn];

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int g = a[0];
	for (int i = 0; i + 1 < n; i++)
		g = gcd(g, a[i + 1] - a[i]);
	int tot = a[n - 1] / g - n;
	printf("%s\n", tot % 2? "Alice": "Bob");
	return 0;
}