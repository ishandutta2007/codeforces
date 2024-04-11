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

const int Maxn = 105;

int n;
int a[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int d = a[1] - a[0];
	bool ok = true;
	for (int i = 0; i + 1 < n && ok; i++)
		ok = a[i + 1] - a[i] == d;
	if (ok) printf("%d\n", a[n - 1] + d);
	else printf("%d\n", a[n - 1]);
	return 0;
}