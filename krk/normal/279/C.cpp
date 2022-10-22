#include <cstdio>
using namespace std;

const int Maxn = 100005;

int n, m;
int a[Maxn], l[Maxn], r[Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	r[n - 1] = n - 1;
	for (int i = n - 2; i >= 0; i--)
		r[i] = a[i] <= a[i + 1]? r[i + 1]: i;
	l[0] = 0;
	for (int i = 1; i < n; i++)
		l[i] = a[i - 1] >= a[i]? l[i - 1]: i;
	while (m--) {
		int v, u; scanf("%d %d", &v, &u);
		if (r[v - 1] >= l[u - 1]) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}