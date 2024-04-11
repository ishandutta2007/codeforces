#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n, k;
int a[Maxn];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		if (i < k) k -= i;
		else { printf("%d\n", a[k]); return 0; }
	return 0;
}