#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 100005;
const int Inf = 1000000000;

int m, n;
int q = Inf, a[Maxn];
int res;

int main()
{
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int qi; scanf("%d", &qi);
		q = min(q, qi);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = n - 1; i >= 0; )
		if (q <= i + 1) {
			for (int j = i; j > i - q; j--)
				res += a[j];
			i -= q;
			i -= min(i + 1, 2);
		} else res += a[i--];
	printf("%d\n", res);
	return 0;
}