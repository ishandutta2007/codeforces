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

typedef long double ld;

const int Maxn = 100000000;

int n;
int best = -Maxn;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		if (a < 0) best = max(best, a);
		else {
			int d = sqrt(ld(a));
			while (d * d > a) d--;
			while ((d + 1) * (d + 1) <= a) d++;
			if (d * d != a) best = max(best, a);
		}
	}
	printf("%d\n", best);
	return 0;
}