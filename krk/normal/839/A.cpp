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

int n, k;
int tot;

int main()
{
	scanf("%d %d", &n, &k);
	int has = 0;
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		has += a;
		int tk = min(8, has); has -= tk; tot += tk;
		if (tot >= k) { printf("%d\n", i); return 0; }
	}
	printf("-1\n");
	return 0;
}