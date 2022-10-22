#include <bits/stdc++.h>
using namespace std;

int T;
int x, y;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &x, &y);
		if (x > y) swap(x, y);
		int res = 2 * x;
		if (x < y) { res++; x++; }
		res += 2 * (y - x);
		printf("%d\n", res);
	}
    return 0;
}