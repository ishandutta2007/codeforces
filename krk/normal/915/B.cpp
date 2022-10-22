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

int n, pos, l, r;

int main()
{
	scanf("%d %d %d %d", &n, &pos, &l, &r);
	int cur = pos;
	int res1 = 0;
	if (l > 1) { res1 += abs(cur - l); cur = l; res1++; }
	if (r < n) { res1 += abs(cur - r); cur = r; res1++; }
	cur = pos;
	int res2 = 0;
	if (r < n) { res2 += abs(cur - r); cur = r; res2++; }
	if (l > 1) { res2 += abs(cur - l); cur = l; res2++; }
	printf("%d\n", min(res1, res2));
	return 0;
}