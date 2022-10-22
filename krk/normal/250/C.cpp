#include <cstdio>
using namespace std;

const int Maxn = 100005;

int n, k;
int a[Maxn];
int delt[Maxn];
int best;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1, j; i <= n; i = j) {
		j = i;
		while (j <= n && a[i] == a[j]) j++;
		delt[a[i]] += a[i - 1] == a[j]? 2: 1;
	}
	best = 1;
	for (int i = 2; i <= k; i++)
		if (delt[i] > delt[best]) best = i;
	printf("%d\n", best);
	return 0;
}