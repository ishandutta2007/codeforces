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

int a, b, f, k;
int res;

int main()
{
	scanf("%d %d %d %d", &a, &b, &f, &k);
	int cur = b;
	while (k > 0) {
		k--;
		if (cur < f) { printf("-1\n"); return 0; }
		cur -= f;
		if (k > 0 && cur < 2 * (a - f) || cur < a - f) { res++; cur = b; }
		cur -= (a - f);
		if (k == 0) break;
		k--;
		if (cur < a - f) { printf("-1\n"); return 0; }
		cur -= (a - f);
		if (k > 0 && cur < 2 * f || cur < f) { res++; cur = b; }
		cur -= f;
	}
	printf("%d\n", cur < 0? -1: res);
	return 0;
}