#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, d;
int a[Maxn];
ll res;

int main()
{
	scanf("%d %d", &n, &d);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		int p = upper_bound(a, a + n, a[i] + d) - a - i;
		res += ll(p - 1) * ll(p - 2) / 2ll;
	}
	printf("%I64d\n", res);
	return 0;
}