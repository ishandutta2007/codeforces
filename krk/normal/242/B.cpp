#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 2000000000;

const int Maxn = 100005;

int n;
int a[Maxn], b[Maxn];
int mn = Inf, mx;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
		mn = min(mn, a[i]); mx = max(mx, b[i]);
	}
	int i = 0;
	while (i < n && (mn < a[i] || b[i] < mx))
		i++;
	if (i < n)
		printf("%d\n", i + 1);
	else printf("-1\n");
	return 0;
}