#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n, q, k;
int a[Maxn];

int main()
{
	scanf("%d %d %d", &n, &q, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	while (q--) {
		int l, r; scanf("%d %d", &l, &r);
		int res = a[l] - 1 + k - a[r] + 2 * (a[r] - a[l] - (r - l));
		printf("%d\n", res);
	}
    return 0;
}