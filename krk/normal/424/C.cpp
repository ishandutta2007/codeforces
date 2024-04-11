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

const int Maxn = 1000005;

int xr[Maxn];
int n;
int res;

int main()
{
	for (int i = 1; i < Maxn; i++)
		xr[i] = i ^ xr[i - 1];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int md = (n + 1) % i;
		res ^= xr[md - 1];
		if ((n + 1) / i % 2 != 0) res ^= xr[i - 1];
	}
	while (n--) {
		int a; scanf("%d", &a);
		res ^= a;
	}
	printf("%d\n", res);
	return 0;
}