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

const int Maxn = 10005;

int n, m;
int a[Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) {
		int l, r, x; scanf("%d %d %d", &l, &r, &x);
		int ls = 0, my = x - l;
		for (int j = l; j <= r && ls <= my; j++)
			ls += a[j] < a[x];
		printf("%s\n", ls == my? "Yes": "No");
	}
	return 0;
}