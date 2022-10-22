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

int n, a, b;

int main()
{
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 1; i <= a && i <= b; i++)
		if (a / (i + 1) + b / (i + 1) < n) {
			printf("%d\n", i);
			return 0;
		}
	printf("%d\n", min(a, b));
	return 0;
}