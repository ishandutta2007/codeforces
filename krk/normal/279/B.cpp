#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n, t;
int a[Maxn];
int best;

int main()
{
	scanf("%d %d", &n, &t);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); if (i) a[i] += a[i - 1];
	}
	for (int i = 0; i < n; i++) {
		int from = i? a[i - 1]: 0;
		int ind = upper_bound(a + i, a + n, from + t) - a;
		best = max(best, ind - i);
	}
	printf("%d\n", best);
	return 0;
}