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

int n, a;

int main()
{
	scanf("%d %d", &n, &a);
	int best = abs(180 - a * n), wth = 1;
	for (int i = 2; i <= n - 2; i++) {
		int cur = abs(i * 180 - a * n);
		if (cur < best) { best = cur; wth = i; }
	}
	printf("2 1 %d\n", 2 + wth);
	return 0;
}