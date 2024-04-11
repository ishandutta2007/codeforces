#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int lim = 1000000;

int n;
int a[Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	res = min(a[n - 1] - 1, lim - a[0]);
	for (int i = 0; i + 1 < n; i++)
		res = min(res, max(a[i] - 1, lim - a[i + 1]));
	printf("%d\n", res);
	return 0;
}