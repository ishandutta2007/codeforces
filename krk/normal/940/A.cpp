#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int n, d;
int x[Maxn];
int res;

int main()
{
	scanf("%d %d", &n, &d);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	sort(x, x + n);
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (x[j] - x[i] <= d) res = max(res, j - i + 1);
	printf("%d\n", n - res);
	return 0;
}