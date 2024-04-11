#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, a, b, c, d;
ll res;

int main()
{
	scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
	for (int x1 = 1; x1 <= n; x1++) {
		int x2 = x1 + b - c;
		int x4 = x1 + a - d;
		int x5 = x1 + a + b - c - d;
		if (1 <= x2 && x2 <= n && 1 <= x4 && x4 <= n && 1 <= x5 && x5 <= n)
			res += n;
	}
	printf("%I64d\n", res);
	return 0;
}