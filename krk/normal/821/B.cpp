#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

int m, b;
ll res;

ll Sum(ll x) { return x * (x + 1) / 2; }

int main()
{
	scanf("%d %d", &m, &b);
	for (int x = 0; x <= m * b; x++) {
		int y = -x / m + b;
		if (x % m) y--;
		if (y >= 0) res = max(res, Sum(x) * ll(y + 1) + Sum(y) * ll(x + 1));
	}
	printf("%I64d\n", res);
	return 0;
}