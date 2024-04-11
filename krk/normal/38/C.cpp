#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n, l;
int a[Maxn];
int res;

int main()
{
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = l; i < Maxn; i++) {
		int cand = 0;
		for (int j = 0; j < n; j++)
			cand += a[j] / i;
		res = max(res, i * cand);
	}
	printf("%d\n", res);
	return 0;
}