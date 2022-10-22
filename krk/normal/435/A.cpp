#include <cstdio>
using namespace std;

const int Maxn = 105;

int n, m;
int a[Maxn];
int res;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0, j; i < n; i = j) {
		j = i;
		int sum = 0;
		while (j < n && sum + a[j] <= m) { sum += a[j]; j++; }
		res++;
	}
	printf("%d\n", res);
	return 0;
}