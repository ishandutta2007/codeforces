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

const int Maxn = 105;

int n;
int a[Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int cur = 0;
	for (int i = 0; i <= n; i++) {
		int cand = cur;
		for (int j = i + 1; j <= n; j++)
			cand += a[j] == 1;
		res = max(res, cand);
		cur += a[i + 1] == 0;
	}
	printf("%d\n", res);
	return 0;
}