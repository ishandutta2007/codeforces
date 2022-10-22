#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

const int Maxn = 2005;

int n;
int a[Maxn];
int cur;
int m;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j]) cur = (cur + 1) % 2;
	scanf("%d", &m);
	while (m--) {
		int l, r; scanf("%d %d", &l, &r);
		int sz = (r - l + 1);
		cur = (cur + sz * (sz - 1) / 2) % 2;
		printf("%s\n", cur == 1? "odd": "even");
	}
	return 0;
}