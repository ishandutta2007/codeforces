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

const int Maxn = 105;

int n, m, k;
int a[Maxn];
int dist = Maxn;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] != 0 && a[i] <= k) dist = min(dist, abs(m - i));
	}
	printf("%d\n", 10 * dist);
	return 0;
}