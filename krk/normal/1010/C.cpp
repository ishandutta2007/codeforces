#include <bits/stdc++.h>
using namespace std;

int n, k;
int a;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
	scanf("%d %d", &n, &k);
	int res = k;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a); a %= k;
		res = gcd(res, a);
	}
	printf("%d\n", k / res);
	for (int i = 0; i < k; i += res)
		printf("%d%c", i, i + res < k? ' ': '\n');
	return 0;
}