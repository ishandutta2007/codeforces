#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n;
int a[Maxn];
int mn, mx;
int res;

int F()
{
	int mn, mx;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) mn = i;
		if (a[i] == n) mx = i;
	}
	return abs(mn - mx);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			swap(a[i], a[j]);
			res = max(res, F());
			swap(a[i], a[j]);
		}
	printf("%d\n", res);
	return 0;
}