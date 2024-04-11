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

const ld Inf = 1e30l;

int n, m;
ld res = Inf;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		res = min(res, ld(a) / b * m);
	}
	cout << fixed << setprecision(10) << res << endl;
	return 0;
}