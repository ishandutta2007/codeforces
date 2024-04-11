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

typedef long long ll;

int n, k;
ll res;

int main()
{
	scanf("%d %d", &n, &k);
	res++;
	if (2 <= k) res += ll(n) * (n - 1) / 2 * 1;
	if (3 <= k) res += ll(n) * (n - 1) * (n - 2) / 6 * 2;
	if (4 <= k) res += ll(n) * (n - 1) * (n - 2) * (n - 3) / 24 * 9;
	printf("%I64d\n", res);
	return 0;
}