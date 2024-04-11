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

int n, k;
int res = 105;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		if (k % a == 0) res = min(res, k / a);
	}
	printf("%d\n", res);
	return 0;
}