#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, m, k;
ll res;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int a = 0; a * a <= n && a <= k; a++) {
		int x = n / (a + 1);
		int y = m / (k - a + 1);
		res = max(res, ll(x) * y);
	}
	for (int x = 1; x * x <= n; x++) {
		int a = n / x - 1;
		if (a > k) { res = max(res, ll(x) * m); continue; }
		int y = m / (k - a + 1);
		res = max(res, ll(x) * y);
	}
	printf("%I64d\n", res? res: -1);
	return 0;
}