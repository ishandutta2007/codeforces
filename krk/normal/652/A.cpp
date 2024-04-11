#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

ll h1, h2;
ll a, b;

int main()
{	
	scanf("%I64d %I64d", &h1, &h2);
	scanf("%I64d %I64d", &a, &b);
	int res = 0;
	while (res <= 1000000) {
		if (res > 0) h1 += 4ll * a;
		h1 += 8ll * a;
		if (h1 >= h2) { printf("%d\n", res); return 0; }
		res++;
		h1 -= 12ll * b;
	}
	printf("-1\n");
	return 0;
}