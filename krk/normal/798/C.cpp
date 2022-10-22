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

const int Maxn = 100005;

int n;
int a[Maxn];

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
	scanf("%d", &n);
	int g = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); g = gcd(g, a[i]);
	}
	printf("YES\n");
	if (g > 1) { printf("0\n"); return 0; }
	int res = 0;
	int i = n - 1;
	while (i >= 0)
		if (a[i] % 2 == 0) i--;
		else if (i > 0) {
			res += 1 + (a[i] % 2 != a[i - 1] % 2);
			a[i] = a[i - 1] = 0;
			i -= 2;
		} else {
			res += 1 + (a[i] % 2 != a[i + 1] % 2);
			a[i] = a[i - 1] = 0;
			i -= 2;
		}
	printf("%d\n", res);
	return 0;
}