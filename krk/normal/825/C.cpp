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

int n, k;
int a[Maxn];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int res = 0;
	for (int i = 0; i < n; i++) {
		int nd = (a[i] + 1) / 2;
		while (k < nd) {
			res++;
			k *= 2;
		}
		k = max(k, a[i]);
	}
	printf("%d\n", res);
	return 0;
}