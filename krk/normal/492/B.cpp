#include <cstdio>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 1005;

int n, l;
int a[Maxn];
ld res;

int main()
{
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	res = a[0];
	for (int i = 1; i < n; i++)
		res = max(res, ld(a[i] - a[i - 1]) / 2.0l);
	res = max(res, ld(l - a[n - 1]));
	printf("%.10lf\n", double(res));
	return 0;
}