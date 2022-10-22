#include <cstdio>
using namespace std;

const int Maxn = 3005;

int n;
int a[Maxn];
int tot;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j]) tot++;
	printf("%.6lf\n", double(tot * 2 - tot % 2));
	return 0;
}