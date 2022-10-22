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

const int Inf = 2000000007;

int mnc = Inf, mxc = -Inf;
int mnp = Inf, mxp = -Inf;
int n, m;
int res;

int main()
{
	scanf("%d", &n);
	while (n--) {
		int l, r; scanf("%d %d", &l, &r);
		mnc = min(mnc, r); mxc = max(mxc, l);
	}
	scanf("%d", &m);
	while (m--) {
		int l, r; scanf("%d %d", &l, &r);
		mnp = min(mnp, r); mxp = max(mxp, l);
	}
	res = max(0, max(mxc - mnp, mxp - mnc));
	printf("%d\n", res);
	return 0;
}