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

const int Maxn = 10005;

int n;
int a[Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 2; i < n; i++)
		res += a[i - 1] < a[i] && a[i] > a[i + 1] ||
			   a[i - 1] > a[i] && a[i] < a[i + 1];
	printf("%d\n", res);
	return 0;
}