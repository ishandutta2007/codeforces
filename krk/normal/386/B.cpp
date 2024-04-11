#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n;
int a[Maxn];
int t;
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &t);
	sort(a, a + n);
	int r = 0;
	for (int l = 0; l < n; l++) {
		while (r < n && a[r] - a[l] <= t) r++;
		res = max(res, r - l);
	}
	printf("%d\n", res);
	return 0;
}