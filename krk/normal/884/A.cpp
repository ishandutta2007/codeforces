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

int n, t;

int main()
{
	scanf("%d %d", &n, &t);
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		t -= (86400 - a);
		if (t <= 0) { printf("%d\n", i); return 0; }
	}
	return 0;
}