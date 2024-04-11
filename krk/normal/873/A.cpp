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

int n, k, x;
int a[Maxn];
int res;

int main()
{
	scanf("%d %d %d", &n, &k, &x);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (i < n - k) res += a[i];
		else res += min(a[i], x);
	}
	printf("%d\n", res);
	return 0;
}