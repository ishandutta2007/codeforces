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

int n, k;

bool Get(int x, int y)
{
	printf("1 %d %d\n", x, y); fflush(stdout);
	string s; cin >> s;
	return s == "TAK";
}

int getLeft(int l, int r)
{
	if (l > r) return l;
	int m = (l + r) / 2;
	if (Get(m, m + 1)) return getLeft(l, m - 1);
	else return getLeft(m + 1, r);
}

int getRight(int l, int r)
{
	if (l > r) return r;
	int m = (l + r) / 2;
	if (Get(m, m - 1)) return getRight(m + 1, r);
	else return getRight(l, m - 1);
}

int tryLeft(int x)
{
	for (int i = 1; x - i >= 1; i <<= 1)
		if (Get(x - i, x - i + 1)) return getLeft(1, x - i - 1);
	return -1;
}

int tryRight(int x)
{
	for (int i = 1; x + i <= n; i <<= 1)
		if (Get(x + i, x + i - 1)) return getRight(x + i + 1, n);
	return -1;
}

int main()
{
	scanf("%d %d", &n, &k);
	int a = getLeft(1, n - 1);
	int b = tryRight(a);
	if (b == -1) b = tryLeft(a);
	printf("2 %d %d\n", a, b); fflush(stdout);
	return 0;
}