#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n, x;
int a[Maxn], b[Maxn];
int res;

int main()
{
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	sort(a, a + n); sort(b, b + n);
	int j = n - 1;
	for (int i = 0; i < n; i++)
		if (a[i] + b[j] >= x) { res++; j--; }
	printf("1 %d\n", res);
	return 0;
}