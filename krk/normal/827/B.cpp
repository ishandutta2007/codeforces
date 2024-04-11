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

int main()
{
	scanf("%d %d", &n, &k);
	int d;
	for (d = 1; ; d++) {
		int newn = (k - 1) * (d / 2) + 1 + d - (d / 2);
		if (newn >= n) { printf("%d\n", d); break; }
	}
	int cur = 2; n--;
	for (int i = 1; i <= k - 1; i++) {
		int add = min(n - k + i, d / 2); n -= add;
		int lst = 1;
		for (int j = 0; j < add; j++) {
			printf("%d %d\n", lst, cur);
			lst = cur++;
		}
	}
	int add = min(n, d - (d / 2));
	int lst = 1;
	for (int j = 0; j < add; j++) {
		printf("%d %d\n", lst, cur);
		lst = cur++;
	}
	return 0;
}