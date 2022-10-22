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

typedef long long ll;

const int Maxn = 100005;

int n, k;
int a[Maxn];
ll res;

int main()
{
	scanf("%d %d", &n, &k);
	int mn = 2000000000;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] % k != a[0] % k) { printf("-1\n"); return 0; }
		mn = min(mn, a[i]);
	}
	for (int i = 0; i < n; i++)
		res += (a[i] - mn) / k;
	printf("%I64d\n", res);
	return 0;
}