#include <algorithm>
#include <cstdio>

int main()
{
	int t, n, a, b, k; scanf("%d%d%d%d%d", &t, &n, &a, &b, &k);
	int A = (n + 1) / 2,
	    B = (n + 0) / 2,
	    res = std::min(1LL * t, (1LL * A * a + 1LL * B * b) / k);
	if (k > A)
		res = std::min(1LL * res, 1LL * B * b / (k - A));
	if (k > B)
		res = std::min(1LL * res, 1LL * A * a / (k - B));
	if (k > n)
		printf("0");
	else 
		printf("%d", res);
	return 0;
}