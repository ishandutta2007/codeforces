#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

int n;
int a, b;

int main()
{
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 0; a * i <= n; i++) {
		int lft = n - a * i;
		if (lft % b == 0) {
			int j = lft / b;
			printf("YES\n");
			printf("%d %d\n", i, j); return 0;
		}
	}
	printf("NO\n");
	return 0;
}