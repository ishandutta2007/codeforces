#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;



int sgn(long long x)
{
	if (x > 0)
		return 1;
	return -1;
}

int main()
{
	int x1, y1, x2, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	int n;
	scanf("%d", &n);

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		long long X = a * 1LL * x1 + b * 1LL * y1 + c;
		long long Y = a * 1LL * x2 + b * 1LL * y2 + c;
		if (sgn(X) != sgn(Y) )
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}