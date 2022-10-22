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

const int Maxn = 205;

int n;
int a[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++)
		scanf("%d", &a[i]);
	sort(a, a + 2 * n);
	if (a[n - 1] == a[n]) {
		printf("NO\n");
	} else printf("YES\n");
	return 0;
}