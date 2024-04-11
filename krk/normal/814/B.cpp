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

const int Maxn = 1005;

int n;
int a[Maxn], b[Maxn];
int c[Maxn];

bool Check(int ind)
{
	int was[Maxn] = {};
	for (int i = 0; i < n; i++)
		if (i != ind) {
			c[i] = a[i];
			was[c[i]]++;
		}
	int val = 0;
	for (int i = 1; i <= n; i++)
		if (was[i] > 1) return false;
		else if (was[i] == 0) val = i;
	c[ind] = val;
	int dif1 = 0, dif2 = 0;
	for (int i = 0; i < n; i++) {
		if (c[i] != a[i]) dif1++;
		if (c[i] != b[i]) dif2++;
	}
	if (dif1 != 1 || dif2 != 1) return false;
	return true;
}

int main()
{
	bool tka = true;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		c[i] = a[i];
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	for (int i = 0; i < n; i++)
		if (Check(i)) break;
	for (int i = 0; i < n; i++)
		printf("%d%c", c[i], i + 1 < n? ' ': '\n');
	return 0;
}