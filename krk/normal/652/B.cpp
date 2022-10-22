#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 1005;

int n;
int a[Maxn];
int res[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int pnt = 0;
	for (int i = 0; i < n; i += 2)
		res[i] = a[pnt++];
	for (int i = 1; i < n; i += 2)
		res[i] = a[pnt++];
	for (int i = 0; i < n; i++)
		printf("%d%c", res[i], i + 1 < n? ' ': '\n');
	return 0;
}