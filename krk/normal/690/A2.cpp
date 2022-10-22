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

int n;

int main()
{
	scanf("%d", &n);
	int res = (n + 1) / 2;
	for (int i = 1; i <= n; i <<= 1)
		if ((n - i) % 2 == 0) res = min(res, (n - i) / 2);
	printf("%d\n", res);
	return 0;
}