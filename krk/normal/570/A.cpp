#include <cstdio>
using namespace std;

const int Maxn = 105;

int n, m;
int a[Maxn];
int res[Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int bj = 1;
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[j]);
			if (a[j] > a[bj]) bj = j;
		}
		res[bj]++;
	}
	int bj = 1;
	for (int j = 1; j <= n; j++)
		if (res[j] > res[bj]) bj = j;
	printf("%d\n", bj);
	return 0;
}