#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int n;
int a[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n / 2; i++)
		scanf("%d", &a[i]);
	sort(a, a + n / 2);
	int res1 = 0, res2 = 0;
	for (int i = 0; i < n / 2; i++) {
		res1 += abs(2 * i + 1 - a[i]);
		res2 += abs(2 * i + 2 - a[i]);
	}
	printf("%d\n", min(res1, res2));
	return 0;
}