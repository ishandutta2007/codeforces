#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 505;

int n, k;
int a[Maxn];
int res;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i++)
		if (a[i - 1] + a[i] < k) {
			int tk = k - (a[i - 1] + a[i]);
			res += tk; a[i] += tk;
		}
	printf("%d\n", res);
	for (int i = 0; i < n; i++)
		printf("%d%c", a[i], i + 1 < n? ' ': '\n');
	return 0;
}