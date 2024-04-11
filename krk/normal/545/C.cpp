#include <cstdio>
using namespace std;

const int Maxn = 100005;

int n;
int x[Maxn], h[Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &x[i], &h[i]);
	int lst = -2000000000;
	for (int i = 0; i < n; i++)
		if (lst < x[i] - h[i]) { res++; lst = x[i]; }
		else if (i + 1 == n || x[i] + h[i] < x[i + 1]) { res++; lst = x[i] + h[i]; }
		else lst = x[i];
	printf("%d\n", res);
	return 0;
}