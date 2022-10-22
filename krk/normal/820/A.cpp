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

int c, v0, v1, a, l;
int res;

int main()
{
	scanf("%d %d %d %d %d", &c, &v0, &v1, &a, &l);
	for (int i = 0; ; i++) {
		c -= min(v1, v0);
		if (c <= 0) { printf("%d\n", i + 1); return 0; }
		c += l; v0 += a;
	}
	return 0;
}