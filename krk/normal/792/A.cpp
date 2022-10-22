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

const int Maxn = 200005;

int n;
int a[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int res = 2000000007, bi = 0;
	for (int i = 0; i + 1 < n; i++) {
		if (a[i + 1] - a[i] < res) { res = a[i + 1] - a[i]; bi = 0; }
		if (a[i + 1] - a[i] == res) bi++;
	}
	printf("%d %d\n", res, bi);
	return 0;
}